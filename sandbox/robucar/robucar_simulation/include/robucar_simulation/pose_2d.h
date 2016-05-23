/*
 * position.h
 *
 *  Created on: Dec 4, 2012
 *      Author: carlos
 */

#ifndef POSITION_H_
#define POSITION_H_

namespace robucar
{

class Pose2d
{
public:
  Pose2d();
  Pose2d(double x, double y, double th, double time);
  virtual ~Pose2d();

  void set(double x, double y, double th, double time);
  void setX(double x);
  void setY(double y);
  double getX();
  double getY();
  double getTh();
  double getTime();

  Pose2d operator + (Pose2d);
  Pose2d operator - (Pose2d);

private:
  // 2d position and orientation.
  double x_, y_, th_, time_;
};

} /* namespace robucar */
#endif /* POSITION_H_ */
