#include <ros/ros.h>

#include "PureDirectoryDevice.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "GetServices");

  if (argc < 2)
  {
    ROS_ERROR("Bad Arguments. Usage: %s <address>", argv[0]);
    return 0;
  }

  PureManager manager;

  ros::NodeHandle node;

  PureDirectoryDevice directory(&manager, &node, argv[1], "directory");

  directory.connect();

  ros::spin();

  return 0;
}
