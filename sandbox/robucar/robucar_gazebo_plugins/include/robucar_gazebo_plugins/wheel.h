/*
 * Wheel.h
 *
 *  Created on: Feb 24, 2012
 *      Author: Carlos Gracia
 */

#ifndef WHEEL_H_
#define WHEEL_H_

#include "gazebo.hh"

#include <ros/ros.h>

#include "common/PID.hh"

namespace gazebo
{

class Wheel
{
public:
  Wheel();
  ~Wheel();

  static void setStepTime(double step_time);

  void init(physics::JointPtr bearingJoint, physics::JointPtr wheelJoint, double bearingMaxForce, double bearingMaxTorque,
            double wheelMaxForce, double wheelMaxTorque, double wheelRadius);

  void setAnglePID(math::Angle required_angle);

  void setSpeed(double required_speed);

  math::Angle getAngle();
  math::Angle getMaxAngle();
  math::Angle getMinAngle();

private:
  static double step_time_;

  double prev_error_, prev_prev_error_, prev_output_, wheel_radius_;

  physics::JointPtr bearing_;
  physics::JointPtr wheel_;

  math::Angle bearing_max_angle_;
  math::Angle bearing_min_angle_;

  common::PID pid_;
  common::Time last_update_time_;
};

}

#endif /* WHEEL_H_ */
