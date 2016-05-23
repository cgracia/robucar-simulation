/*
 * path.h
 *
 *  Created on: Dec 5, 2012
 *      Author: carlos
 */

#ifndef PATH_H_
#define PATH_H_

#include "robucar_simulation/pose_2d.h"

#include <vector>

namespace robucar
{

class Path
{
public:
  Path();
  virtual ~Path();

  void addPose(Pose2d pose);
  unsigned int getSize();
  Pose2d getPose(unsigned int number);
  Pose2d getLastPose();

  static void drawAll();

private:
  void changeInitialPose (Pose2d initial_pose);

  std::vector<Pose2d> path_;

  static std::vector<Path*> all_paths_;

  double getMaxX();
  double getMinX();
  double getMaxY();
  double getMinY();
};

} /* namespace robucar */
#endif /* PATH_H_ */
