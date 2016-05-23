#include <ros/ros.h>

#include "robucar_simulation/plot_path.h"

#include <iostream>

#include "dislin.h"

// The idea here is just to publish the required speed.
int main(int argc, char **argv)
{
  ros::init(argc, argv, "simulation_control");
  ros::NodeHandle n;

  metafl("cons");
  disini();
  messag("This is a test", 100, 100);
  disfin();

  // TODO: Write a subscriber to the odomometry
  // TODO: Plot the robot position and path from the odometry
  // TODO: Ask Luis this makes sense or not.

  ros::spin();
}
