cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
rosbuild_add_library(rospure
                             src/PureFrame.h
                             src/PureDevice.cpp
                             src/PureDevice.h
                             src/PureManager.cpp
                             src/PureManager.h
                             src/TCPTransceiver.cpp
                             src/TCPTransceiver.h
                             src/PureLaserDevice.cpp
                             src/PureLaserDevice.h
                             src/PureCarDevice.cpp
                             src/PureCarDevice.h
                             src/PureDriveDevice.cpp
                             src/PureDriveDevice.h
                             src/PureLocalizationDevice.cpp
                             src/PureLocalizationDevice.h
                             src/PureGpsDevice.cpp
                             src/PureGpsDevice.h
                             src/VirtualCrabDevice.cpp
                             src/VirtualCrabDevice.h
                             src/PureDirectoryDevice.cpp
                             src/PureDirectoryDevice.h
                             )

#rosbuild_add_boost_directories()
#rosbuild_link_boost(rosbucar thread)

rosbuild_add_executable(rosbucar src/RosbuCar.cpp)

target_link_libraries(rosbucar boost_thread rospure)

rosbuild_add_executable(get_services src/get_services.cpp)
target_link_libraries(get_services rospure)

rosbuild_add_executable(car2odom src/car2odom.cpp)
#target_link_libraries(car2odom rospure)

rosbuild_add_executable(clock src/clock.cpp)
#target_link_libraries(car2odom rospure)

rosbuild_add_executable(repair_scan src/repair_scan.cpp)
rosbuild_add_executable(localization2tf src/localization2tf.cpp)
