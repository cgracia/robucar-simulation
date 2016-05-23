#include "ros/ros.h"

#include "robucar_simulation/SpeedRequest.h"

#include "gazebo/ApplyBodyWrench.h" // Remember you have to add dependencies to the manifest.
#include "gazebo/ApplyJointEffort.h"

#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Wrench.h"

#include <iostream>
#include <string>

#include "LinearMath/btMatrix3x3.h"
#include "LinearMath/btQuaternion.h"


// Wheel.
class Wheel
{
private:
  std::string wheel_joint_name;
  double position_radians;
  double max_position_radians;
  double min_position_radians;
  
public:
  Wheel(std::string);
  static ros::ServiceClient * joint_effort_client; //Remember, not a definition.
  bool jointEffort(double effort);
};

// Class for making the robot do things.
class RobotAction
{
private:
  double required_force [3];
  double required_torque [3];
  // Apply a wrench to the base_link.
  bool applyWrench(double required_force [], double required_torque [], std::string body_name);
  // Calculate the actions needed to get the requested speed.
  void calculateActions(double linear_speed, double angular_speed);

public:
  // Constructor.
  RobotAction();

  // Callback for the "speed_request server".
  bool speedRequest(robucar_simulation::SpeedRequest::Request& request,
                    robucar_simulation::SpeedRequest::Response& response);

  // Pointer to the "gazebo/apply_body_wrench" client.
  ros::ServiceClient * apply_wrench_client;

  // Pointers to the wheels.
  Wheel * front_left_wheel;
};

// Trying to create a node that reads speed and then makes the little simulated robot move.
int main(int argc, char **argv)
{
  // Initialize node.
  ros::init(argc, argv, "set_speed");
  ros::NodeHandle nh;

  // Create objects.
  RobotAction robucar_action;
  Wheel front_left_wheel("front_axle_to_front_left_wheel");
//std::cout <<"front_axle_to_front_left_wheel";

  // Advertise the service for speed requests.
  ros::ServiceServer service = nh.advertiseService("speed_request", &RobotAction::speedRequest, &robucar_action);

  // Set up the "gazebo/apply_body_wrench" client.
  ros::ServiceClient apply_wrench_client = nh.serviceClient<gazebo::ApplyBodyWrench>("gazebo/apply_body_wrench");
  robucar_action.apply_wrench_client = &apply_wrench_client; // Need a way to find the client inside the class.

  // Set up the "gazebo/apply_joint_effort" client.
  //ros::ServiceClient joint_effort_client = nh.serviceClient<gazebo::ApplyJointEffort>("gazebo/apply_joint_effort");
  //Wheel::joint_effort_client = &joint_effort_client; // It will be used by all the wheels.

/*
// Playing with strange things:
btQuaternion q;
q.setRPY(0,0.05,0);
double roll, pitch, yaw;
btMatrix3x3(q).getRPY(roll, pitch, yaw);
std::cout << "roll " << roll << "pitch " << pitch << "yaw " << yaw; */

  ros::spin();
  return 0;
}

//////////////////////////////
// RobotAction definitions. //
//////////////////////////////

// Constructor.
RobotAction::RobotAction()
{
}

// Apply a wrench to the robot.
bool RobotAction::applyWrench(double required_force [], double required_torque [], std::string body_name)
{
  gazebo::ApplyBodyWrench srv; // This goes here?
  //srv.request.body_name = "robucar::base_link";
//srv.request.body_name = "robucar::front_left_wheel";
srv.request.body_name = "robucar::" + body_name;

  //srv.request.reference_frame = ""; //Use inertial frame if empty.

  geometry_msgs::Vector3 required_force_vector3 = geometry_msgs::Vector3();
  required_force_vector3.x = required_force[0];
  required_force_vector3.y = required_force[1];
  required_force_vector3.z = required_force[2];
  geometry_msgs::Vector3 required_torque_vector3 = geometry_msgs::Vector3();
  required_torque_vector3.x = required_torque[0];
  required_torque_vector3.y = required_torque[1];
  required_torque_vector3.z = required_torque[2];
  geometry_msgs::Wrench required_wrench = geometry_msgs::Wrench();
  required_wrench.force = required_force_vector3;
  required_wrench.torque = required_torque_vector3;
  srv.request.wrench = required_wrench;

  ros::Time wrench_time(0.0);
  srv.request.start_time = wrench_time;

  ros::Duration wrench_duration(-1);
  srv.request.duration = wrench_duration;

  //ROS_INFO("Am I ready?");
  //if(ros::service::exists("gazebo/apply_body_wrench",true)) ROS_INFO("I am ready");

  //if (ros::service::call("gazebo/apply_body_wrench",srv))
  if (apply_wrench_client->call(srv))
  {
    ROS_INFO("gazebo/apply_body_wrench succesfully called.");
  }
  else
  {
    ROS_ERROR("Failed to call service.");
    return false;
  }
  return true;
}


bool RobotAction::speedRequest(robucar_simulation::SpeedRequest::Request& request,
                  robucar_simulation::SpeedRequest::Response& response )
{
 // ROS_INFO("request: lin=%ld, ang=%ld", (long int)request.linear_speed, (long int)request.angular_speed);

  required_force = {0,0,0};
  required_torque = {0,request.linear_speed,0};
  applyWrench(required_force,required_torque,"front_left_wheel");

  //front_left_wheel->jointEffort(100.0);

  return true;
}


////////////////////////
// Wheel definitions. //
////////////////////////

// Constructor.
Wheel::Wheel(std::string name)
{
  wheel_joint_name = "robucar::" + name;
}

// Static pointer to client.
ros::ServiceClient * Wheel::joint_effort_client;

// 
bool Wheel::jointEffort(double effort)
{
  gazebo::ApplyJointEffort srv;

if(ros::service::exists("gazebo/apply_joint_effort",true)) ROS_INFO("I am ready");

  srv.request.joint_name = wheel_joint_name;

  srv.request.effort = effort;

  ros::Time effort_time(0.0);
  srv.request.start_time = effort_time;

  ros::Duration effort_duration(-1);
  srv.request.duration = effort_duration;

  if(ros::service::exists("gazebo/apply_joint_effort",true)) ROS_INFO("I am still ready");

  if (joint_effort_client->call(srv))
  {
    ROS_INFO("gazebo/apply_joint_effort succesfully called.");
  }
  else
  {
    ROS_ERROR("Failed to call service.");
    return false;
  }
  return true;
}
