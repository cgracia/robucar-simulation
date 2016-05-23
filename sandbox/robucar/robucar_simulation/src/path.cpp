/*
 * path.cpp
 *
 *  Created on: Dec 5, 2012
 *      Author: carlos
 */

#include "robucar_simulation/path.h"

#include <iostream>
#include <cmath>
#include "discpp.h"

#include <ros/ros.h>

namespace robucar
{

std::vector<Path*> Path::all_paths_;

Path::Path()
{
  Path* pointer = this;
  all_paths_.push_back(pointer);
}

Path::~Path()
{
}

void Path::addPose(Pose2d pose)
{
  path_.push_back(pose);
}

unsigned int Path::getSize()
{
  return path_.size();
}

Pose2d Path::getPose(unsigned int number)
{
  return path_.at(number);
}

Pose2d Path::getLastPose()
{
  return path_.at(path_.size() - 1);
}

void Path::drawAll()
{
  //ROS_INFO("Max x is %f",all_paths_.at(0)->getMaxX());
  //ROS_INFO("Min x is %f",all_paths_.at(0)->getMinX());
  //ROS_INFO("Max y is %f",all_paths_.at(0)->getMaxY());
  //ROS_INFO("Min y is %f",all_paths_.at(0)->getMinY());

  // Adjust paths so that they all start in the same pose.
  // TODO: Translation adjusted, need to rotate.
  for (unsigned int i = 1; i < all_paths_.size(); i++)
  {
    all_paths_.at(i)->changeInitialPose(all_paths_.at(0)->getPose(0));
  }

  // Limits for the plot.
  double max_x = all_paths_.at(0)->getMaxX();
  double min_x = all_paths_.at(0)->getMinX();
  double max_y = all_paths_.at(0)->getMaxY();
  double min_y = all_paths_.at(0)->getMinY();

  for (unsigned int i = 1; i < all_paths_.size(); i++)
  {
    if (max_x < all_paths_.at(i)->getMaxX())
    {
      max_x = all_paths_.at(i)->getMaxX();
    }
    if (min_x > all_paths_.at(i)->getMinX())
    {
      min_x = all_paths_.at(i)->getMinX();
    }
    if (max_y < all_paths_.at(i)->getMaxY())
    {
      max_y = all_paths_.at(i)->getMaxY();
    }
    if (min_y > all_paths_.at(i)->getMinY())
    {
      min_y = all_paths_.at(i)->getMinY();
    }
  }

  // TODO: Consider maintaining form, same scaling in both axis.
  // Add some padding
  double padding_factor = 0.1;
  double x_pad = padding_factor * std::abs(max_x - min_x);
  double y_pad = padding_factor * std::abs(max_y - min_y);
  max_x += x_pad;
  min_x -= x_pad;
  max_y += y_pad;
  min_y -= y_pad;

  Dislin g;

  g.metafl("cons");
  g.scrmod("revers");
  g.disini();
  g.pagera();
  g.complx();
  g.axspos(450, 1650);
  g.axslen(2200, 1200);

  g.name("X-axis", "x");
  g.name("Y-axis", "y");

  g.labdig(-1, "x");
  g.ticks(4, "x");
  g.ticks(4, "y");

  g.titlin("Robot paths:", 1);
  g.titlin("Red: Real", 2);
  g.titlin("Green: Simulated", 3);
  g.titlin("Blue: Theoretical", 4);

  int ic = g.intrgb(0.95, 0.95, 0.95);
  g.axsbgd(ic);

  double x_step = std::abs(max_x - min_x) / 10;
  double y_step = std::abs(max_y - min_y) / 10;

  g.graf(min_x, max_x, min_x, x_step, min_y, max_y, min_y, y_step);
  g.setrgb(0.7, 0.7, 0.7);
  g.grid(1, 1);

  g.color("fore");
  g.height(50);
  g.title();

  // Drawing paths (red).
  for (unsigned int path = 0; path < all_paths_.size(); path++)
  //for (unsigned int path = 0; path < 2; path++)
  {
    if (all_paths_.at(path)->getSize() > 0)
    {
      unsigned int n = all_paths_.at(path)->getSize();
      double xray[n], yray[n];
      for (unsigned int i = 0; i < n; i++)
      {
        xray[i] = all_paths_.at(path)->getPose(i).getX();
        yray[i] = all_paths_.at(path)->getPose(i).getY();
      }
      switch (path)
      {
        case 0:
          ROS_INFO("Drawing real path (red)");
          g.color("red");
          break;
        case 1:
          ROS_INFO("Drawing simulated path (green)");
          g.color("green");
          break;
        case 2:
          ROS_INFO("Drawing theoretical path (blue)");
          g.color("blue");
          break;
        default:
          g.color("black");
          break;
      }
      g.curve(xray, yray, n);
    }
  }

  g.disfin();
}

void Path::changeInitialPose(Pose2d initial_pose)
{
  // Compute the difference between initial_pose and the first pose in the path and change all poses.
  Pose2d difference = initial_pose - path_.at(0);

  for (unsigned int i = 0; i < path_.size(); i++)
  {
    path_.at(i) = difference + path_.at(i);
  }

  // Rotate the paths so that all of them start with the same orientation.
  double angle = difference.getTh();

  for (unsigned int i = 0; i < path_.size(); i++)
  {
    double x = path_.at(i).getX();
    double y = path_.at(i).getY();
    x -= initial_pose.getX();
    y -= initial_pose.getY();
    double new_x = (x * cos(angle)) - (y * sin(angle));
    double new_y = (x * sin(angle)) + (y * cos(angle));
    new_x += initial_pose.getX();
    new_y += initial_pose.getY();
    path_.at(i).setX(new_x);
    path_.at(i).setY(new_y);
  }
}

double Path::getMaxX()
{
  double max = path_.at(0).getX();

  for (unsigned int i = 1; i < path_.size(); i++)
  {
    if (path_.at(i).getX() > max)
    {
      max = path_.at(i).getX();
    }
  }

  return max;
}

double Path::getMinX()
{
  double min = path_.at(0).getX();

  for (unsigned int i = 1; i < path_.size(); i++)
  {
    if (path_.at(i).getX() < min)
    {
      min = path_.at(i).getX();
    }
  }

  return min;
}

double Path::getMaxY()
{
  double max = path_.at(0).getY();

  for (unsigned int i = 1; i < path_.size(); i++)
  {
    if (path_.at(i).getY() > max)
    {
      max = path_.at(i).getY();
    }
  }

  return max;
}

double Path::getMinY()
{
  double min = path_.at(0).getY();

  for (unsigned int i = 1; i < path_.size(); i++)
  {
    if (path_.at(i).getY() < min)
    {
      min = path_.at(i).getY();
    }
  }

  return min;
}

} /* namespace robucar */
