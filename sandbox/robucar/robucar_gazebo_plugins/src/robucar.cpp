/*
 * Robucar.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: Carlos Gracia
 */

#include "robucar_gazebo_plugins/robucar.h"

#include <math.h>

using namespace gazebo;

Robucar::Robucar()
{
}

Robucar::~Robucar()
{
}

double Robucar::getAxleSeparation()
{
  return axle_separation_;
}

void Robucar::setWheelRadius(double wheel_radius)
{
  wheel_radius_ = wheel_radius;
}

void Robucar::setAxleLength(double axle_length)
{
  axle_length_ = axle_length;
}

void Robucar::setAxleSeparation(double axle_separation)
{
  axle_separation_ = axle_separation;
}

void Robucar::setForceLimit(double force_limit)
{
  force_limit_ = force_limit;
}

void Robucar::setWheel(int position_x, int position_y, physics::JointPtr bearing_joint, physics::JointPtr wheel_joint)
{
  wheel_[position_x][position_y].init(bearing_joint, wheel_joint, force_limit_, force_limit_, force_limit_,
                                      force_limit_, wheel_radius_);
}

void Robucar::setLinearSpeedLimit(double linear_speed_limit)
{
  linear_speed_limit_ = linear_speed_limit;
}

void Robucar::setWheelTurnLimit(double wheel_turn_limit)
{
  wheel_turn_limit_.SetFromRadian(wheel_turn_limit);
}

void Robucar::setSpeed(double required_linear_speed, double required_wheel_angle, char required_mode)
{
  if (required_mode == CAR)
  {
    double required_angular_speed;

    // Angles that will be sent to the wheels.
    math::Angle angle[2][2];

    // Check whether the robot is expected to turn or not, in order to avoid division by 0.
    if (required_wheel_angle == 0.0)
    {
      angle[FRONT][LEFT].SetFromRadian(0.0);
      angle[FRONT][RIGHT].SetFromRadian(0.0);
      required_angular_speed = 0;
    }
    else
    {
      // Calculate turn radius and required angular speed.
      double turn_radius = axle_separation_ / tan(required_wheel_angle);
      required_angular_speed = required_linear_speed / turn_radius;

      if (required_wheel_angle > 0) // Turn left.
      {
        angle[FRONT][LEFT].SetFromRadian(atan(axle_separation_ / (std::abs(turn_radius) - (axle_length_ / 2))));
        angle[FRONT][RIGHT].SetFromRadian(atan(axle_separation_ / (std::abs(turn_radius) + (axle_length_ / 2))));
      }
      else // Turn right.
      {
        angle[FRONT][LEFT].SetFromRadian(-atan(axle_separation_ / (std::abs(turn_radius) + (axle_length_ / 2))));
        angle[FRONT][RIGHT].SetFromRadian(-atan(axle_separation_ / (std::abs(turn_radius) - (axle_length_ / 2))));
      }
    }

    // Since we are in car mode, back wheels are straight.
    angle[BACK][LEFT].SetFromRadian(0.0);
    angle[BACK][RIGHT].SetFromRadian(0.0);

    // Saturation, don't ask the controller for an angle outside its limits.
    // TODO: Move the saturation to the wheel class.
    for (int i = 0; i <= 1; i++)
    {
      if (angle[FRONT][i] > wheel_[FRONT][i].getMaxAngle())
      {
        angle[FRONT][i] = wheel_[FRONT][i].getMaxAngle();
      }
    }

    // TODO: Plot things to tune the PID constants.
    //geometry_msgs::Twist msg;
    //pub = nh.advertise<geometry_msgs::Twist>("checkPID", 5);
    //msg.linear.x = front_left_angle.GetAsRadian();
    //msg.linear.y = front_left_bearing->GetAngle(0).GetAsRadian();
    //msg.linear.z = (Simulator::Instance()->GetSimTime()).Double();
    //pub.publish(msg);

    double speed[2][2];

    // Check whether the robot has go forwards of backwards.
    int speed_sign;
    if (required_linear_speed != 0)
    {
      speed_sign = required_linear_speed / std::abs(required_linear_speed);
    }
    else
    {
      speed_sign = 0;
    }

    // TODO: It may not be correct going backwards, check.
    speed[FRONT][LEFT] = speed_sign
        * sqrt(
            pow(required_linear_speed - (required_angular_speed * axle_length_ / 2), 2)
                + pow(required_angular_speed * axle_separation_, 2));
    speed[FRONT][RIGHT] = speed_sign
        * sqrt(
            pow(required_linear_speed + (required_angular_speed * axle_length_ / 2), 2)
                + pow(required_angular_speed * axle_separation_, 2));
    speed[BACK][LEFT] = required_linear_speed - (required_angular_speed * axle_length_ / 2);
    speed[BACK][RIGHT] = required_linear_speed + (required_angular_speed * axle_length_ / 2);

    // Send the commands to the wheels.
    for (int i = 0; i <= 1; i++)
    {
      for (int j = 0; j <= 1; j++)
      {
        wheel_[i][j].setSpeed(speed[i][j]);
        wheel_[i][j].setAnglePID(angle[i][j]);
      }
    }
  }
  /*
   else if (required_mode == DUAL)
   {
   double turn_radius;
   math::Angle angle[2][2];

   // Check whether the robot is expected to turn or not, in order to avoid division by 0.

   if (required_angular_speed_ == 0.0)
   {
   angle[FRONT][LEFT].SetFromRadian(0.0);
   angle[FRONT][RIGHT].SetFromRadian(0.0);
   angle[BACK][LEFT].SetFromRadian(0.0);
   angle[BACK][RIGHT].SetFromRadian(0.0);
   }
   else
   {
   turn_radius = required_linear_speed_ / required_angular_speed_;
   if (required_angular_speed_ > 0) // Turn left.
   {
   angle[FRONT][LEFT].SetFromRadian(atan(axle_separation_ / (2 * (abs(turn_radius) - (axle_length_ / 2)))));
   angle[FRONT][RIGHT].SetFromRadian(atan(axle_separation_ / (2 * (abs(turn_radius) + (axle_length_ / 2)))));
   angle[BACK][LEFT].SetFromRadian(-atan(axle_separation_ / (2 * (abs(turn_radius) - (axle_length_ / 2)))));
   angle[BACK][RIGHT].SetFromRadian(-atan(axle_separation_ / (2 * (abs(turn_radius) + (axle_length_ / 2)))));
   }
   else // Turn right.
   {
   angle[FRONT][LEFT].SetFromRadian(-atan(axle_separation_ / (2 * (abs(turn_radius) + (axle_length_ / 2)))));
   angle[FRONT][RIGHT].SetFromRadian(-atan(axle_separation_ / (2 * (abs(turn_radius) - (axle_length_ / 2)))));
   angle[BACK][LEFT].SetFromRadian(atan(axle_separation_ / (2 * (abs(turn_radius) + (axle_length_ / 2)))));
   angle[BACK][RIGHT].SetFromRadian(atan(axle_separation_ / (2 * (abs(turn_radius) - (axle_length_ / 2)))));
   }
   }

   // Saturation, don't ask the controller for an angle outside its limits.
   // TODO: Calculate maximum turning radius, use that as a limit.

   for (int i = 0; i <= 1; i++)
   {
   for (int j = 0; j <= 1; j++)
   {
   if (angle[i][j] > wheel_[i][j].GetMaxAngle())
   {
   angle[i][j] = wheel_[i][j].GetMaxAngle();
   }
   }
   }

   // TODO: Plot things to tune the PID constants.
   //geometry_msgs::Twist msg;
   //pub = nh.advertise<geometry_msgs::Twist>("checkPID", 5);
   //msg.linear.x = front_left_angle.GetAsRadian();
   //msg.linear.y = front_left_bearing->GetAngle(0).GetAsRadian();
   //msg.linear.z = (Simulator::Instance()->GetSimTime()).Double();
   //pub.publish(msg);

   double speed[2][2];

   if (required_angular_speed_ > 0) // Turn left.
   {
   speed[FRONT][LEFT] = sqrt(
   pow(required_linear_speed_ - (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[FRONT][RIGHT] = sqrt(
   pow(required_linear_speed_ + (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[BACK][LEFT] = sqrt(
   pow(required_linear_speed_ - (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[BACK][RIGHT] = sqrt(
   pow(required_linear_speed_ + (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   }
   else // Turn right.
   {
   speed[FRONT][LEFT] = sqrt(
   pow(required_linear_speed_ + (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[FRONT][RIGHT] = sqrt(
   pow(required_linear_speed_ - (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[BACK][LEFT] = sqrt(
   pow(required_linear_speed_ + (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   speed[BACK][RIGHT] = sqrt(
   pow(required_linear_speed_ - (required_angular_speed_ * axle_length_ / 2), 2)
   + pow(required_angular_speed_ * axle_separation_ / 2, 2));
   }

   // Send the commands to the wheels.
   for (int i = 0; i <= 1; i++)
   {
   for (int j = 0; j <= 1; j++)
   {
   wheel_[i][j].setSpeed(speed[i][j]);
   wheel_[i][j].setAnglePID(angle[i][j]);
   }
   }
   }
   else if (required_mode == CRAB)
   {
   double turn_radius; // Not really, just used to get the proper relation between wheel angles.
   math::Angle angle[2][2], required_robot_angle, required_angle[2];

   boost::mutex::scoped_lock lock(mutex_);

   // TODO: Temporal use of required_angular_speed_ as required angle for crab mode.
   required_robot_angle = required_angular_speed_;

   if (required_robot_angle == 0.0)
   {
   angle[FRONT][LEFT].SetFromRadian(0.0);
   angle[FRONT][RIGHT].SetFromRadian(0.0);
   angle[BACK][LEFT].SetFromRadian(0.0);
   angle[BACK][RIGHT].SetFromRadian(0.0);
   }
   else
   {
   // Lovely trigonometry and rigid body kinematics.
   turn_radius = axle_separation_ / (2 * tan(std::abs(required_robot_angle.GetAsRadian())));

   if (required_robot_angle > 0) // Move right.
   {
   required_angle[LEFT].SetFromRadian(atan(axle_separation_ / (2 * (turn_radius + (axle_length_ / 2)))));
   required_angle[RIGHT].SetFromRadian(atan(axle_separation_ / (2 * (turn_radius - (axle_length_ / 2)))));
   }
   else // Move left.
   {
   required_angle[LEFT].SetFromRadian(atan(axle_separation_ / (2 * (turn_radius - (axle_length_ / 2)))));
   required_angle[RIGHT].SetFromRadian(atan(axle_separation_ / (2 * (turn_radius + (axle_length_ / 2)))));
   }

   angle[FRONT][LEFT].SetFromRadian(required_angle[LEFT].GetAsRadian());
   angle[FRONT][RIGHT].SetFromRadian(required_angle[RIGHT].GetAsRadian());
   angle[BACK][LEFT].SetFromRadian(required_angle[LEFT].GetAsRadian());
   angle[BACK][RIGHT].SetFromRadian(required_angle[RIGHT].GetAsRadian());
   }

   for (int i = 0; i <= 1; i++)
   {
   for (int j = 0; j <= 1; j++)
   {
   wheel_[i][j].setSpeed(required_linear_speed_);
   wheel_[i][j].setAnglePID(angle[i][j]);
   }
   }
   }
   else
   {
   gzthrow("No mode selected.");
   }
   */
}

