/*
 * Robucar.h
 *
 *  Created on: Mar 30, 2012
 *      Author: Carlos Gracia
 */

#ifndef ROBUCAR_H_
#define ROBUCAR_H_

#include "robucar_gazebo_plugins/wheel.h"

#include "physics/physics.h"

namespace gazebo
{

class Robucar
{
public:
  Robucar();
  ~Robucar();

  double getAxleSeparation();

  // Setup
  void setWheelRadius (double wheel_radius);
  void setAxleLength (double axle_length);
  void setAxleSeparation (double axle_separation);
  void setForceLimit(double force_limit);
  void setWheel(int position_x, int position_y, physics::JointPtr bearing_joint, physics::JointPtr wheel_joint);
  void setLinearSpeedLimit(double linear_speed_limit);
  void setWheelTurnLimit(double wheel_turn_limit);

  // Speed, angle and mode command for the robot.
  void setSpeed(double required_linear_speed, double required_wheel_angle, char required_mode);

  enum Mode
  {
    CAR, DUAL, CRAB
  };

private:
  enum PositionX
  {
    FRONT, BACK
  };

  enum PositionY
  {
    LEFT, RIGHT
  };

  physics::ModelPtr parent_;

  Wheel wheel_[2][2];

  double wheel_radius_;
  double axle_length_;
  double axle_separation_;
  double force_limit_;
  double linear_speed_limit_;
  math::Angle wheel_turn_limit_;
};

}

#endif /* ROBUCAR_H_ */
