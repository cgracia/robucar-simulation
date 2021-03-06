/* Auto-generated by genmsg_cpp for file /home/carlos/fuerte_workspace/sandbox/rosbucar/msg/CarLikeInfo.msg */
#ifndef ROSBUCAR_MESSAGE_CARLIKEINFO_H
#define ROSBUCAR_MESSAGE_CARLIKEINFO_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace rosbucar
{
template <class ContainerAllocator>
struct CarLikeInfo_ {
  typedef CarLikeInfo_<ContainerAllocator> Type;

  CarLikeInfo_()
  : header()
  , status(0)
  , current_speed(0.0)
  , current_steering(0.0)
  , target_speed(0.0)
  , target_steering(0.0)
  {
  }

  CarLikeInfo_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , status(0)
  , current_speed(0.0)
  , current_steering(0.0)
  , target_speed(0.0)
  , target_steering(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint8_t _status_type;
  uint8_t status;

  typedef float _current_speed_type;
  float current_speed;

  typedef float _current_steering_type;
  float current_steering;

  typedef float _target_speed_type;
  float target_speed;

  typedef float _target_steering_type;
  float target_steering;


  typedef boost::shared_ptr< ::rosbucar::CarLikeInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosbucar::CarLikeInfo_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct CarLikeInfo
typedef  ::rosbucar::CarLikeInfo_<std::allocator<void> > CarLikeInfo;

typedef boost::shared_ptr< ::rosbucar::CarLikeInfo> CarLikeInfoPtr;
typedef boost::shared_ptr< ::rosbucar::CarLikeInfo const> CarLikeInfoConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::rosbucar::CarLikeInfo_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::rosbucar::CarLikeInfo_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace rosbucar

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::rosbucar::CarLikeInfo_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::rosbucar::CarLikeInfo_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::rosbucar::CarLikeInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "f4b94786e7837b141f54f295f70c7a3d";
  }

  static const char* value(const  ::rosbucar::CarLikeInfo_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xf4b94786e7837b14ULL;
  static const uint64_t static_value2 = 0x1f54f295f70c7a3dULL;
};

template<class ContainerAllocator>
struct DataType< ::rosbucar::CarLikeInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "rosbucar/CarLikeInfo";
  }

  static const char* value(const  ::rosbucar::CarLikeInfo_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::rosbucar::CarLikeInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
uint8 status\n\
float32 current_speed\n\
float32 current_steering\n\
float32 target_speed\n\
float32 target_steering\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::rosbucar::CarLikeInfo_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::rosbucar::CarLikeInfo_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::rosbucar::CarLikeInfo_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::rosbucar::CarLikeInfo_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.status);
    stream.next(m.current_speed);
    stream.next(m.current_steering);
    stream.next(m.target_speed);
    stream.next(m.target_steering);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct CarLikeInfo_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosbucar::CarLikeInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::rosbucar::CarLikeInfo_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "current_speed: ";
    Printer<float>::stream(s, indent + "  ", v.current_speed);
    s << indent << "current_steering: ";
    Printer<float>::stream(s, indent + "  ", v.current_steering);
    s << indent << "target_speed: ";
    Printer<float>::stream(s, indent + "  ", v.target_speed);
    s << indent << "target_steering: ";
    Printer<float>::stream(s, indent + "  ", v.target_steering);
  }
};


} // namespace message_operations
} // namespace ros

#endif // ROSBUCAR_MESSAGE_CARLIKEINFO_H

