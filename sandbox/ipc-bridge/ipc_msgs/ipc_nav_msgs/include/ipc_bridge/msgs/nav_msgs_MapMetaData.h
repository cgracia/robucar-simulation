/* automatically generated by xdrgen from xdr/nav_msgs_MapMetaData.xdr
 * xdrgen cvs version: $Revision: 1.7 $ $Date: 2009/01/12 15:54:59 $
 * xdr/nav_msgs_MapMetaData.xdr last modified: Thu Nov 11 11:15:54 2010
 */

#ifndef INCnav_msgs_MapMetaData_h
#define INCnav_msgs_MapMetaData_h



#include <ipc_bridge/msgs/geometry_msgs_Pose.h>


struct nav_msgs_MapMetaData {
  double map_load_time;
  float resolution;
  unsigned int width;
  unsigned int height;
  geometry_msgs_Pose origin;
#define nav_msgs_MapMetaData_IPC_FORMAT "{double,float,uint,uint," geometry_msgs_Pose_IPC_FORMAT "}"
  static const char *getIPCFormat(void) {
    return nav_msgs_MapMetaData_IPC_FORMAT;
  }
};


namespace ipc_bridge
{
    namespace nav_msgs
    {
        typedef nav_msgs_MapMetaData MapMetaData;
    }
}


#endif /* INCnav_msgs_MapMetaData_h */
