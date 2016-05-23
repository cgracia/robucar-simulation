/*
 * Wheel.cpp
 *
 *  Created on: Feb 24, 2012
 *      Author: carlos
 */

#include "robucar_gazebo_plugins/wheel.h"

#include "physics/PhysicsTypes.hh"
#include "physics/physics.h"

using namespace gazebo;

// Actually, PID_saturation is the max speed it can be asked for (to set the wheel position)
const double PID_saturation = 0.5;

// PID constants:
const double Kp = 50;
const double Ti = 5;
const double Td = 1;

////////////////////////////////////////////////////////////////////////////////
// Wheel class.

Wheel::Wheel()
{
  prev_error_ = 0;
  prev_prev_error_ = 0;
  prev_output_ = 0;
}

Wheel::~Wheel()
{
}

double Wheel::step_time_;

void Wheel::setStepTime(double step_time)
{
  step_time_ = step_time;
}

void Wheel::init(physics::JointPtr bearingJoint, physics::JointPtr wheelJoint, double bearingMaxForce,
                 double bearingMaxTorque, double wheelMaxForce, double wheelMaxTorque, double wheelRadius)
{
  bearing_ = bearingJoint;
  wheel_ = wheelJoint;

  bearing_->SetMaxForce(0,bearingMaxForce);
  wheel_->SetMaxForce(0,wheelMaxForce);

  bearing_max_angle_ = bearing_->GetHighStop(0);
  bearing_min_angle_ = bearing_->GetLowStop(0);

  wheel_radius_ = wheelRadius;

  pid_.Init(2, 0.5, 0.5, 1, -1, 0.1, -0.1);
  pid_.SetCmd(0.0);
  last_update_time_ = bearing_->GetWorld()->GetSimTime();
}

// TODO: Get a better, non overshooting control.
// TODO: Output to a file/graphic the control result to check how well it is working.

void Wheel::setAnglePID(math::Angle required_angle)
{
  /*
step_time_ = 0.1;
  double error = required_angle.GetAsRadian() - bearing_->GetAngle(0).GetAsRadian();
  std::cout << "Required angle is: " << required_angle.GetAsRadian();
  std::cout << " Real angle is: " << bearing_->GetAngle(0).GetAsRadian() << std::endl;

  double output = prev_output_
      + Kp
          * ((1 + step_time_ / Ti + Td / step_time_) * error + (-1 - 2 * Td / step_time_) * prev_error_
              + Td / step_time_ * prev_prev_error_);

  // Introduce saturation, should prevent windup.
  if (output > PID_saturation)
  {
    output = PID_saturation;
  }
  else if (output < -PID_saturation)
  {
    output = -PID_saturation;
  }

  bearing_->SetVelocity(0, output);

  prev_prev_error_ = prev_error_;
  prev_error_ = error;
  prev_output_ = output;
  */

  common::Time current_time = bearing_->GetWorld()->GetSimTime();
  double error = bearing_->GetAngle(0).GetAsRadian()
               - required_angle.GetAsRadian();
  double dt    = current_time.Double()
               - last_update_time_.Double();
  pid_.Update(error, dt);
  bearing_->SetVelocity(0, pid_.GetCmd());
  last_update_time_ = current_time;
}

// Calculate the angular speed of the wheel from its required linear speed.
void Wheel::setSpeed(double required_speed)
{
  double angular_speed = required_speed / wheel_radius_;
  wheel_->SetVelocity(0, angular_speed);
}

math::Angle Wheel::getMaxAngle()
{
  return bearing_max_angle_;
}

math::Angle Wheel::getMinAngle()
{
  return bearing_min_angle_;
}

math::Angle Wheel::getAngle()
{
  return bearing_->GetAngle(0);
}
