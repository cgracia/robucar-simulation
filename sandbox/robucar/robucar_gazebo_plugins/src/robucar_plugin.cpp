/*
 * Desc: Gazebo plugin for a Robucar
 * Author: Carlos Gracia
 * Date: 19/01/2012
 */

#include "robucar_gazebo_plugins/robucar_plugin.h"

#include <algorithm>
#include <assert.h>
#include <math.h>

#include <ros/ros.h>
#include <std_msgs/builtin_double.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

#include <boost/bind.hpp>

#include "rosbucar/CarLikeInfo.h"

enum PositionX
{
  FRONT, BACK
};

enum PositionY
{
  LEFT, RIGHT
};

const double PI = 4 * atan(1.0);

using namespace gazebo;

const std::string RobucarPlugin::param_name_bearing_[2][2] = { {"frontLeftBearingName", "frontRightBearingName"}, {
    "backLeftBearingName", "backRightBearingName"}};
const std::string RobucarPlugin::param_name_wheel_[2][2] = { {"frontLeftWheelName", "frontRightWheelName"}, {
    "backLeftWheelName", "backRightWheelName"}};

////////////////////////////////////////////////////////////////////////////////
// Constructor
RobucarPlugin::RobucarPlugin()
{
}

////////////////////////////////////////////////////////////////////////////////
// Destructor
RobucarPlugin::~RobucarPlugin()
{
  alive_ = false;

  // Custom Callback Queue
  queue_.clear();
  queue_.disable();
  rosnode_->shutdown();
  callback_queue_thread_->join();
}

////////////////////////////////////////////////////////////////////////////////
// Load the controller
void RobucarPlugin::Load(physics::ModelPtr parent, sdf::ElementPtr sdf)
{
  alive_ = true;

  // Get then name of the parent sensor
  parent_ = parent;

  // Get the world name.
  world_ = parent->GetWorld();

  // Get the physics engine. Step time is needed for the discrete PID controller.
  // TODO: Is this needed anymore?
  physics::PhysicsEnginePtr engine = world_->GetPhysicsEngine();
  double step_time = engine->GetStepTime();
  Wheel::setStepTime(step_time);
  ROS_INFO("Simulation step time is %f seconds.", step_time);
  ROS_INFO("Simulation update rate is %f.", engine->GetUpdateRate());

  robot_namespace_ = "";
  if (sdf->HasElement("robotNamespace"))
  {
    robot_namespace_ = sdf->GetElement("robotNamespace")->GetValueString() + "/";
  }

  if (!sdf->HasElement("topicName"))
  {
    ROS_WARN("Robucar plugin missing <topicName>, defaults to /world");
    this->topic_name_ = "/world";
  }
  else
  {
    this->topic_name_ = sdf->GetElement("topicName")->GetValueString();
  }

  // Get the names of the joints to be controlled.
  // Bearings:
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      if (!sdf->HasElement(param_name_bearing_[i][j]))
      {
        bearing_name_[i][j] = "";
      }
      else
      {
        bearing_name_[i][j] = sdf->GetElement(param_name_bearing_[i][j])->GetValueString();
      }
      if (!sdf->HasElement(param_name_wheel_[i][j]))
      {
        wheel_name_[i][j] = "";
      }
      else
      {
        wheel_name_[i][j] = sdf->GetElement(param_name_wheel_[i][j])->GetValueString();
      }
    }
  }

  // Get the pointers to the joints.
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      bearing_joint_[i][j] = parent_->GetJoint(bearing_name_[i][j]);
      wheel_joint_[i][j] = parent_->GetJoint(wheel_name_[i][j]);
    }
  }

  // Check whether the joints are loaded or not.
  if (!bearing_joint_[FRONT][LEFT])
    gzthrow("The controller couldn't get front_left_bearing");
  if (!wheel_joint_[FRONT][LEFT])
    gzthrow("The controller couldn't get front_left_wheel");
  if (!bearing_joint_[FRONT][RIGHT])
    gzthrow("The controller couldn't get front_right_bearing");
  if (!wheel_joint_[FRONT][RIGHT])
    gzthrow("The controller couldn't get front_right_wheel");
  if (!bearing_joint_[BACK][LEFT])
    gzthrow("The controller couldn't get back_left_bearing");
  if (!wheel_joint_[BACK][LEFT])
    gzthrow("The controller couldn't get back_left_wheel");
  if (!bearing_joint_[BACK][RIGHT])
    gzthrow("The controller couldn't get back_right_bearing");
  if (!wheel_joint_[BACK][RIGHT])
    gzthrow("The controller couldn't get back_right_wheel");

  // Get geometry.
  if (!sdf->HasElement("wheelRadius"))
  {
    ROS_WARN("Robucar plugin missing <wheelRadius>, defaults to 1.0");
    robucar_.setWheelRadius(1);
  }
  else
  {
    robucar_.setWheelRadius(sdf->GetElement("wheelRadius")->GetValueDouble());
  }
  if (!sdf->HasElement("axleLength"))
  {
    ROS_WARN("Robucar plugin missing <axleLength>, defaults to 1.0");
    robucar_.setAxleLength(1);
  }
  else
  {
    robucar_.setAxleLength(sdf->GetElement("axleLength")->GetValueDouble());
  }

  if (!sdf->HasElement("axleSeparation"))
  {
    ROS_WARN("Robucar plugin missing <axleSeparation>, defaults to 1.0");
    robucar_.setAxleSeparation(1);
  }
  else
  {
    robucar_.setAxleSeparation(sdf->GetElement("axleSeparation")->GetValueDouble());
  }

  // TODO: Get software limits and use them.

  // Initialize wheels.
  // Right now we do not care about forces, the limit is set high enough so it doesn't do anything. Limits will be kinematic.
  robucar_.setForceLimit(5000000);
  for (int i = 0; i <= 1; i++)
  {
    for (int j = 0; j <= 1; j++)
    {
      robucar_.setWheel(i, j, bearing_joint_[i][j], wheel_joint_[i][j]);
    }
  }

  // Set initial speed to 0, angle to 0, CAR mode.
  required_linear_speed_ = 0;
  required_wheel_angle_ = 0;
  required_mode_ = Robucar::CAR;

  // Initialize the ROS node and subscribe to cmd_vel.
  int argc = 0;
  char** argv = NULL;
  ros::init(argc, argv, "robucar_plugin", ros::init_options::NoSigintHandler | ros::init_options::AnonymousName);
  rosnode_ = new ros::NodeHandle(robot_namespace_);

  tf_prefix_ = tf::getPrefixParam(*rosnode_);
  transform_broadcaster_ = new tf::TransformBroadcaster();

  // ROS: Subscribe to the velocity command topic (usually "cmd_vel")
  ros::SubscribeOptions so;
  so = ros::SubscribeOptions::create<rosbucar::CarLikeCmd>(topic_name_, 1,
                                                           boost::bind(&RobucarPlugin::cmdVelCallback, this, _1),
                                                           ros::VoidPtr(), &queue_);
  sub_ = rosnode_->subscribe(so);
  odometry_publisher_ = rosnode_->advertise<nav_msgs::Odometry>("odometry", 1);
  car_like_info_publisher_ = rosnode_->advertise<rosbucar::CarLikeInfo>("car_like_info", 1);

  // To calculate the angular speed from the wheel angle axle separation is needed.
  //ros::ServiceServer service = rosnode_->advertiseService("axle_separation", boost::bind(&RobucarPlugin::axleSeparationCallback, this));

  //ros::ServiceServer service = rosnode_->advertiseService("axle_separation", &RobucarPlugin::axleSeparationCallback, this);

  axle_separation_publisher_ = rosnode_->advertise<std_msgs::Float64>("axle_separation", 1);

  // Listen to the update event. This event is broadcast every simulation iteration.
  update_connection_ = event::Events::ConnectWorldUpdateStart(boost::bind(&RobucarPlugin::OnUpdate, this));
  last_update_time_ = world_->GetSimTime();
}

////////////////////////////////////////////////////////////////////////////////
// Initialize the controller
void RobucarPlugin::Init()
{
  callback_queue_thread_ = new boost::thread(boost::bind(&RobucarPlugin::QueueThread, this));
}

////////////////////////////////////////////////////////////////////////////////
// Update the controller
void RobucarPlugin::OnUpdate()
{
  if (world_->IsPaused())
  {
    ROS_INFO("World is paused");
  }
  else if (!parent_)
  {
    ROS_INFO("Model does not exist");
    return;
  }
  else
  {
    // Update the controller only every hundred ms (for example)
    common::Time current_time = world_->GetSimTime();
    if ((current_time.Double() - last_update_time_.Double()) > 0.1)
    {
      last_update_time_ = world_->GetSimTime();
      robucar_.setSpeed(required_linear_speed_, required_wheel_angle_, required_mode_);
      publishOdometry();

      axle_separation_publisher_.publish(robucar_.getAxleSeparation());
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// Get and publish odometry.
void RobucarPlugin::publishOdometry()
{
  // Get current time and position from the simulator
  mutex_.lock();
  ros::Time current_time(world_->GetSimTime().sec, world_->GetSimTime().nsec);
  math::Pose current_pose = parent_->GetWorldPose();
  math::Vector3 current_linear_vel = parent_->GetWorldLinearVel();
  math::Vector3 current_angular_vel = parent_->GetWorldAngularVel();
  mutex_.unlock();

  // TODO: Getting the angular velocity from the world reference is not working well

  // Odometry
  nav_msgs::Odometry odometry;

  odometry.header.stamp = current_time;
  odometry.header.frame_id = "world";
  odometry.child_frame_id = "robot";

  odometry.pose.pose.position.x = current_pose.pos.x;
  odometry.pose.pose.position.y = current_pose.pos.y;
  odometry.pose.pose.position.z = current_pose.pos.z;

  odometry.pose.pose.orientation.w = current_pose.rot.w;
  odometry.pose.pose.orientation.x = current_pose.rot.x;
  odometry.pose.pose.orientation.y = current_pose.rot.y;
  odometry.pose.pose.orientation.z = current_pose.rot.z;

  odometry.twist.twist.linear.x = current_linear_vel.x;
  odometry.twist.twist.linear.y = current_linear_vel.y;
  odometry.twist.twist.linear.z = current_linear_vel.z;

  odometry.twist.twist.angular.x = current_angular_vel.x;
  odometry.twist.twist.angular.y = current_angular_vel.y;
  odometry.twist.twist.angular.z = current_angular_vel.z;

  odometry_publisher_.publish(odometry);

  // Car like info

  rosbucar::CarLikeInfo car_like_info;

  car_like_info.header.stamp = current_time;
  car_like_info.status = 0; // TODO: What goes here?

  // Find out whether the robot is moving forwards or backwards.
  math::Vector3 robot_orientation = current_pose.rot.GetAsEuler();
  double speed_angle_z = atan2(current_linear_vel.y, current_linear_vel.x);
  int speed_sign;
  if (std::abs(speed_angle_z - robot_orientation.z) < PI / 2)
  {
    speed_sign = 1;
  }
  else
  {
    speed_sign = -1;
  }
  // Speed in the z axis should be useful for slopes.
  car_like_info.current_speed = speed_sign
      * sqrt(pow(current_linear_vel.x, 2) + pow(current_linear_vel.y, 2) + pow(current_linear_vel.z, 2));
  car_like_info.current_steering = current_angular_vel.z;
  car_like_info.target_speed = required_linear_speed_;
  car_like_info.target_steering = required_wheel_angle_;

  car_like_info_publisher_.publish(car_like_info);
}

////////////////////////////////////////////////////////////////////////////////
// Store the velocities from the ROS message.
void RobucarPlugin::cmdVelCallback(const rosbucar::CarLikeCmdConstPtr & command)
{
  boost::mutex::scoped_lock lock(mutex_);

  required_linear_speed_ = command->target_speed;
  required_wheel_angle_ = command->target_steering;
  //required_linear_speed_ = 0.5;
  //required_wheel_angle_ = -0.4;

  required_mode_ = Robucar::CAR;

  // TODO: Sim time is not real time, commands do not arrive when they should. Can you fix it?

  //rostopic pub /robucar/cmd_vel robucar_gazebo_plugins/CarLikeCmd -- '0' '0.2' '0.0'

  // TODO: Assume we are just using car mode, find out later how is the mode chosen (take into account that messages are different)
  /*
   if ((cmd_msg->linear.y > -0.5) && (cmd_msg->linear.y < 0.5))
   {
   required_mode_ = Robucar::CAR;
   }
   else if (cmd_msg->linear.y < 1.5)
   {
   required_mode_ = Robucar::DUAL;
   }
   else if (cmd_msg->linear.y < 2.5)
   {
   required_mode_ = Robucar::CRAB;
   }
   */
}

////////////////////////////////////////////////////////////////////////////////
// Custom callback queue thread
void RobucarPlugin::QueueThread()
{
  static const double timeout = 0.01;

  while (alive_ && rosnode_->ok())
  {
    queue_.callAvailable(ros::WallDuration(timeout));
  }
}

GZ_REGISTER_MODEL_PLUGIN(RobucarPlugin);
