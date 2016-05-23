/*
 * extract_vel_cmd.cpp
 *
 *  Created on: Oct 29, 2012
 *      Author: carlos
 */

// It should read from a CarLikeInfo message, extract its info and turn it into a CarLikeCmd message.
// The idea is to get commands for the simulation from a real bag file from the robot.

#include <ros/ros.h>

#include "rosbucar/CarLikeCmd.h"
#include "rosbucar/CarLikeInfo.h"

// Yes, I know this is an evil global variable, but it is such a small program...
ros::Publisher publisher;

void carInfoCallback(const rosbucar::CarLikeInfo::ConstPtr& car_like_info)
{

  rosbucar::CarLikeCmd car_like_cmd;

  car_like_cmd.action = 0; // TODO: What is action?
  car_like_cmd.target_speed = car_like_info->target_speed;
  car_like_cmd.target_steering = car_like_info->target_steering;

  publisher.publish(car_like_cmd);


  //ROS_INFO("Target speed is %f",car_like_info->target_speed);
  //ROS_INFO("Current speed is %f",car_like_info->current_speed);
  //ROS_INFO("Target steering is %f",car_like_info->target_steering);
  //ROS_INFO("Current steering is %f\n",car_like_info->current_steering);
  // TODO: In the bag file the target speed is always 0 and steering is always positive (except at the end when target speed is around e-45 and steering varies wildly)
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "extract_vel_cmd");

  ros::NodeHandle node_handle;

  publisher = node_handle.advertise<rosbucar::CarLikeCmd>("car/in", 1000);

  ros::Subscriber subscriber = node_handle.subscribe("car/out", 1000, carInfoCallback);

  ROS_INFO("Ready to transform messages.");

  ros::spin();
}
