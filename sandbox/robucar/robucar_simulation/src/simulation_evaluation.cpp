#include <ros/ros.h>

#include "robucar_simulation/pose_2d.h"
#include "robucar_simulation/path.h"

#include "gazebo.hh"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/builtin_double.h>

#include "rosbucar/CarLikeInfo.h"

// Paths were the trajectories will be stored.
// Aren't global variables lovely?
robucar::Path real_path;
robucar::Path simulated_path;
robucar::Path theoretical_path;

bool finished;
bool recording;
double last_message_time;
double axle_separation;

// TODO: Only start recording when real robot messages start to arrive?

void real_robot_callback(const geometry_msgs::PoseWithCovarianceStamped& pose_message)
{
  //ROS_INFO("Hi! 1");
  recording = true;
  double x = pose_message.pose.pose.position.x;
  double y = pose_message.pose.pose.position.y;
  gazebo::math::Quaternion quaternion(pose_message.pose.pose.orientation.w, pose_message.pose.pose.orientation.x,
                                      pose_message.pose.pose.orientation.y, pose_message.pose.pose.orientation.z);
  double th = quaternion.GetYaw();
  robucar::Pose2d pose(x, y, th, ros::WallTime::now().toSec());
  real_path.addPose(pose);

  last_message_time = ros::WallTime::now().toSec();
}

void simulated_robot_callback(const nav_msgs::Odometry& odometry_message)
{
  //ROS_INFO("Hi! 2");
  if (recording)
  {
    double x = odometry_message.pose.pose.position.x;
    double y = odometry_message.pose.pose.position.y;
    gazebo::math::Quaternion quaternion(odometry_message.pose.pose.orientation.w,
                                        odometry_message.pose.pose.orientation.x,
                                        odometry_message.pose.pose.orientation.y,
                                        odometry_message.pose.pose.orientation.z);
    double th = quaternion.GetYaw();
    ROS_INFO("X: %f Y: %f", x, y);
    robucar::Pose2d pose(x, y, th, ros::Time::now().toSec());
    simulated_path.addPose(pose);
  }
  //last_message_time = ros::Time::now();
}

void velocity_command_callback(const rosbucar::CarLikeInfoConstPtr& info_message)
{
  //ROS_INFO("Hi! 3");

  if (recording)
  {
    robucar::Pose2d last_pose = theoretical_path.getLastPose();
    double current_time = ros::WallTime::now().toSec();
    double deltaT = current_time - last_pose.getTime();
    double x = last_pose.getX();
    double y = last_pose.getY();
    double th = last_pose.getTh();

    double linear_speed = info_message->target_speed;
    double wheel_angle = info_message->target_steering;
    double angular_speed;

    // TODO: Add a service for robucar_plugin to tell the axle_separation, ask for it here in main before doing anything else.
    // It seems Gazebo needs a ServerPlugin to advertise a service. Using a message instead, at least for now.

    // Check whether the robot is expected to turn or not, in order to avoid division by 0.
    if (wheel_angle == 0.0)
    {
      angular_speed = 0;
    }
    else
    {
      // Calculate turn radius and required angular speed.
      double turn_radius = axle_separation / tan(wheel_angle);
      angular_speed = linear_speed / turn_radius;
    }

    double deltaX, deltaY, deltaTh;

    if (angular_speed == 0)
    {
      deltaX = linear_speed * cos(th) * deltaT;
      deltaY = linear_speed * sin(th) * deltaT;
      deltaTh = 0;
    }
    else
    {
      deltaX = (linear_speed / angular_speed) * (sin(th + (angular_speed * deltaT)) - sin(th));
      deltaY = -(linear_speed / angular_speed) * (cos(th + (angular_speed * deltaT)) - cos(th));
      deltaTh = angular_speed * deltaT;
    }

    robucar::Pose2d new_pose(x + deltaX, y + deltaY, th + deltaTh, current_time);
    theoretical_path.addPose(new_pose);
  }
  //last_message_time = ros::Time::now();
}

void axle_separation_callback(const std_msgs::Float64& message)
{
  //ROS_INFO("Hi! 4");
  axle_separation = message.data;
}

// The idea here is just to publish the required speed.
int main(int argc, char **argv)
{
  ros::init(argc, argv, "simulation_control");
  ros::NodeHandle node_handle;

  // Theoretical path starts at 0, it will be changed to the starting point of the real one once all the messages have been received.
  // Using WallTime, Time is problematic because it can change suddenly whenever a rosbag is played.
  robucar::Pose2d pose(0, 0, 0, ros::WallTime::now().toSec());
  theoretical_path.addPose(pose);

  // Subscribe to all the topics needed.
  // Odometry of the real robot.
  ros::Subscriber real_robot_subscriber = node_handle.subscribe("localization/out", 1000, real_robot_callback);

  // Odometry of the simulated robot.
  ros::Subscriber simulated_robot_subscriber = node_handle.subscribe("robucar/odometry", 1000,
                                                                     simulated_robot_callback);

  // Speed commands to get a theoretical path.
  ros::Subscriber velocity_command_subscriber = node_handle.subscribe("car/out", 1000, velocity_command_callback);

  // TODO: Not the best way to do this, but as long as it works...
  ros::Subscriber axle_separation_subscriber = node_handle.subscribe("robucar/axle_separation", 1000,
                                                                     axle_separation_callback);

  // finished will be set to true when there is no real robot messages for a while.
  finished = false;
  recording = false;
  last_message_time = ros::WallTime::now().toSec() + 60; // Wait 60 seconds for the first message.

  ROS_INFO("Ready to receive messages");
  while (!finished)
  {
    //ROS_INFO("Last message time is %f./nCurrent time is %f.",last_message_time.toSec(),ros::Time::now().toSec());
    ros::spinOnce();

    if ((last_message_time + 1) < ros::WallTime::now().toSec())
    {
      finished = true;
    }
  }

  ROS_INFO("Drawing all paths");
  robucar::Path::drawAll();

  // TODO: Need a correction, all three robots should start in the same pose.
  // TODO: It would be nice to draw the final pose of the robot (including orientation, of course)

  return 0;
}
