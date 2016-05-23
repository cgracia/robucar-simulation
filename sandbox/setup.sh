#!/bin/sh
source /opt/ros/diamondback/setup.bash
export ROS_ROOT=/opt/ros/diamondback/ros
export PATH=$ROS_ROOT/bin:$PATH
export PYTHONPATH=$ROS_ROOT/core/roslib/src:$PYTHONPATH
export ROS_PACKAGE_PATH=~/ros_workspace:/opt/ros/diamondback/stacks:$ROS_PACKAGE_PATH
export LD_LIBRARY_PATH=`rospack find ipc`/lib:`rospack find roscpp`/lib:`rospack find roscpp_serialization`/lib:`rospack find xmlrpcpp`/lib:`rospack find rosconsole`/lib:`rospack find roslib`/lib:`rospack find rospack`/lib:`rospack find rostime`/lib:`rospack find cpp_common`/lib:${LD_LIBRARY_PATH}
export PATH=/usr/local/MATLAB/R2011b/bin:$PATH
DISLIN=/usr/local/dislin
export DISLIN
LD_LIBRARY_PATH=${DISLIN}:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH
export PATH=${DISLIN}:$PATH
