/*
 * position.cpp
 *
 *  Created on: Dec 4, 2012
 *      Author: carlos
 */

#include "robucar_simulation/pose_2d.h"

namespace robucar
{

Pose2d::Pose2d()
{
}

Pose2d::Pose2d(double x, double y, double th, double time)
{
  x_ = x;
  y_ = y;
  th_ = th;
  time_ = time;
}

Pose2d::~Pose2d()
{
}

void Pose2d::set(double x, double y, double th, double time)
{
  x_ = x;
  y_ = y;
  th_ = th;
  time_ = time;
}

void Pose2d::setX(double x)
{
  x_ = x;
}

void Pose2d::setY(double y)
{
  y_ = y;
}

double Pose2d::getX()
{
  return x_;
}

double Pose2d::getY()
{
  return y_;
}

double Pose2d::getTh()
{
  return th_;
}

double Pose2d::getTime()
{
  return time_;
}

Pose2d Pose2d::operator+(Pose2d param)
{
  Pose2d temp(x_ + param.getX(), y_ + param.getY(), th_ + param.getTh(), param.getTime());
  return (temp);
}

Pose2d Pose2d::operator-(Pose2d param)
{
  Pose2d temp(x_ - param.getX(), y_ - param.getY(), th_ - param.getTh(), param.getTime());
  return (temp);
}

} /* namespace robucar */
