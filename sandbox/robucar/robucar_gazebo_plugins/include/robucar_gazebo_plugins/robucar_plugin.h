/*
 * Desc: Gazebo plugin for a Robucar
 * Author: Carlos Gracia
 * Date: 19/01/2012
 */

#ifndef ROBUCAR_PLUGIN_HH
#define ROBUCAR_PLUGIN_HH

#include "gazebo.hh"
#include "physics/PhysicsTypes.hh"
#include "physics/physics.h"

// ROS
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>

// Custom Callback Queue
#include <ros/callback_queue.h>
#include <ros/advertise_options.h>

#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include "robucar_gazebo_plugins/robucar.h"

#include "rosbucar/CarLikeCmd.h"

namespace gazebo
{

class RobucarPlugin : public ModelPlugin
{
  /// \brief Constructor
public:
  RobucarPlugin();

  /// \brief Destructor
public:
  virtual ~RobucarPlugin();

  /// \brief Load the controller
  /// \param node XML config node
protected:
  virtual void Load(physics::ModelPtr parent, sdf::ElementPtr sdf);

  /// \brief Init the controller
protected:
  virtual void Init();

  /// \brief Update the controller
protected:
  virtual void OnUpdate();

protected:
  virtual void publishOdometry();

private:
  void cmdVelCallback(const rosbucar::CarLikeCmdConstPtr & command);

  Robucar robucar_;

  physics::ModelPtr parent_;
  physics::WorldPtr world_;
  event::ConnectionPtr update_connection_;

  common::Time last_update_time_;

  physics::JointPtr bearing_joint_[2][2];
  physics::JointPtr wheel_joint_[2][2];

  std::string robot_namespace_;
  std::string topic_name_;

  std::string bearing_name_[2][2];
  std::string wheel_name_[2][2];

  static const std::string param_name_bearing_[2][2];
  static const std::string param_name_wheel_[2][2];

  double required_linear_speed_;
  double required_wheel_angle_;
  char required_mode_;
  bool alive_;

  // ROS STUFF
  ros::NodeHandle* rosnode_;
  ros::Subscriber sub_;
  tf::TransformBroadcaster *transform_broadcaster_;
  std::string tf_prefix_;

  boost::mutex mutex_;

  // Custom Callback Queue
  ros::CallbackQueue queue_;
  boost::thread* callback_queue_thread_;
  void QueueThread();

  ros::Publisher odometry_publisher_;
  ros::Publisher car_like_info_publisher_;
  ros::Publisher axle_separation_publisher_;
};

}
#endif
