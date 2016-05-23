/* Auto-generated by genmsg_cpp for file /home/carlos/fuerte_workspace/sandbox/gps_novatel/msg/NovatelInfo.msg */
#ifndef GPS_NOVATEL_MESSAGE_NOVATELINFO_H
#define GPS_NOVATEL_MESSAGE_NOVATELINFO_H
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

namespace gps_novatel
{
template <class ContainerAllocator>
struct NovatelInfo_ {
  typedef NovatelInfo_<ContainerAllocator> Type;

  NovatelInfo_()
  : header()
  , sol_status(0)
  , pos_type(0)
  , lat(0.0)
  , lon(0.0)
  , alt(0.0)
  , ondulation(0.0)
  , datum_id(0)
  , sigmaLat(0.0)
  , sigmaLon(0.0)
  , sigmaAlt(0.0)
  , base_id()
  , diff_age(0.0)
  , sol_age(0.0)
  , nObs(0)
  , nGPSL(0)
  , nL1(0)
  , nL2(0)
  {
  }

  NovatelInfo_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , sol_status(0)
  , pos_type(0)
  , lat(0.0)
  , lon(0.0)
  , alt(0.0)
  , ondulation(0.0)
  , datum_id(0)
  , sigmaLat(0.0)
  , sigmaLon(0.0)
  , sigmaAlt(0.0)
  , base_id(_alloc)
  , diff_age(0.0)
  , sol_age(0.0)
  , nObs(0)
  , nGPSL(0)
  , nL1(0)
  , nL2(0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef uint16_t _sol_status_type;
  uint16_t sol_status;

  typedef uint16_t _pos_type_type;
  uint16_t pos_type;

  typedef double _lat_type;
  double lat;

  typedef double _lon_type;
  double lon;

  typedef double _alt_type;
  double alt;

  typedef double _ondulation_type;
  double ondulation;

  typedef uint16_t _datum_id_type;
  uint16_t datum_id;

  typedef double _sigmaLat_type;
  double sigmaLat;

  typedef double _sigmaLon_type;
  double sigmaLon;

  typedef double _sigmaAlt_type;
  double sigmaAlt;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _base_id_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  base_id;

  typedef double _diff_age_type;
  double diff_age;

  typedef double _sol_age_type;
  double sol_age;

  typedef uint16_t _nObs_type;
  uint16_t nObs;

  typedef uint16_t _nGPSL_type;
  uint16_t nGPSL;

  typedef uint16_t _nL1_type;
  uint16_t nL1;

  typedef uint16_t _nL2_type;
  uint16_t nL2;


  typedef boost::shared_ptr< ::gps_novatel::NovatelInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gps_novatel::NovatelInfo_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct NovatelInfo
typedef  ::gps_novatel::NovatelInfo_<std::allocator<void> > NovatelInfo;

typedef boost::shared_ptr< ::gps_novatel::NovatelInfo> NovatelInfoPtr;
typedef boost::shared_ptr< ::gps_novatel::NovatelInfo const> NovatelInfoConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::gps_novatel::NovatelInfo_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::gps_novatel::NovatelInfo_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace gps_novatel

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::gps_novatel::NovatelInfo_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::gps_novatel::NovatelInfo_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::gps_novatel::NovatelInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "fffc7fc92588667ebe9605af5853709c";
  }

  static const char* value(const  ::gps_novatel::NovatelInfo_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xfffc7fc92588667eULL;
  static const uint64_t static_value2 = 0xbe9605af5853709cULL;
};

template<class ContainerAllocator>
struct DataType< ::gps_novatel::NovatelInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "gps_novatel/NovatelInfo";
  }

  static const char* value(const  ::gps_novatel::NovatelInfo_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::gps_novatel::NovatelInfo_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
uint16 sol_status\n\
uint16 pos_type\n\
float64 lat\n\
float64 lon\n\
float64 alt\n\
float64 ondulation\n\
uint16 datum_id \n\
float64 sigmaLat\n\
float64 sigmaLon\n\
float64 sigmaAlt\n\
string base_id\n\
float64 diff_age\n\
float64 sol_age\n\
uint16 nObs\n\
uint16 nGPSL\n\
uint16 nL1\n\
uint16 nL2\n\
\n\
\n\
\n\
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

  static const char* value(const  ::gps_novatel::NovatelInfo_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::gps_novatel::NovatelInfo_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::gps_novatel::NovatelInfo_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::gps_novatel::NovatelInfo_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.sol_status);
    stream.next(m.pos_type);
    stream.next(m.lat);
    stream.next(m.lon);
    stream.next(m.alt);
    stream.next(m.ondulation);
    stream.next(m.datum_id);
    stream.next(m.sigmaLat);
    stream.next(m.sigmaLon);
    stream.next(m.sigmaAlt);
    stream.next(m.base_id);
    stream.next(m.diff_age);
    stream.next(m.sol_age);
    stream.next(m.nObs);
    stream.next(m.nGPSL);
    stream.next(m.nL1);
    stream.next(m.nL2);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct NovatelInfo_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gps_novatel::NovatelInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::gps_novatel::NovatelInfo_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "sol_status: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.sol_status);
    s << indent << "pos_type: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.pos_type);
    s << indent << "lat: ";
    Printer<double>::stream(s, indent + "  ", v.lat);
    s << indent << "lon: ";
    Printer<double>::stream(s, indent + "  ", v.lon);
    s << indent << "alt: ";
    Printer<double>::stream(s, indent + "  ", v.alt);
    s << indent << "ondulation: ";
    Printer<double>::stream(s, indent + "  ", v.ondulation);
    s << indent << "datum_id: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.datum_id);
    s << indent << "sigmaLat: ";
    Printer<double>::stream(s, indent + "  ", v.sigmaLat);
    s << indent << "sigmaLon: ";
    Printer<double>::stream(s, indent + "  ", v.sigmaLon);
    s << indent << "sigmaAlt: ";
    Printer<double>::stream(s, indent + "  ", v.sigmaAlt);
    s << indent << "base_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.base_id);
    s << indent << "diff_age: ";
    Printer<double>::stream(s, indent + "  ", v.diff_age);
    s << indent << "sol_age: ";
    Printer<double>::stream(s, indent + "  ", v.sol_age);
    s << indent << "nObs: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.nObs);
    s << indent << "nGPSL: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.nGPSL);
    s << indent << "nL1: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.nL1);
    s << indent << "nL2: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.nL2);
  }
};


} // namespace message_operations
} // namespace ros

#endif // GPS_NOVATEL_MESSAGE_NOVATELINFO_H

