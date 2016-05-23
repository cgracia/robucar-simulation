/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/RosbuCar.cpp
 *  Authors: Danilo Tardioli
 *  ----------------------------------------------------------------------
 *  Copyright (C) 2000-2010, Universidad de Zaragoza, SPAIN
 *
 *  Contact Addresses: Danilo Tardioli                   dantard@unizar.es
 *
 *  RT-WMP is free software; you can  redistribute it and/or  modify it
 *  under the terms of the GNU General Public License  as published by the
 *  Free Software Foundation;  either  version 2, or (at  your option) any
 *  later version.
 *
 *  RT-WMP  is distributed  in the  hope  that  it will be   useful, but
 *  WITHOUT  ANY  WARRANTY;     without  even the   implied   warranty  of
 *  MERCHANTABILITY  or  FITNESS FOR A  PARTICULAR PURPOSE.    See the GNU
 *  General Public License for more details.
 *
 *  You should have received  a  copy of  the  GNU General Public  License
 *  distributed with RT-WMP;  see file COPYING.   If not,  write to the
 *  Free Software  Foundation,  59 Temple Place  -  Suite 330,  Boston, MA
 *  02111-1307, USA.
 *
 *  As a  special exception, if you  link this  unit  with other  files to
 *  produce an   executable,   this unit  does  not  by  itself cause  the
 *  resulting executable to be covered by the  GNU General Public License.
 *  This exception does  not however invalidate  any other reasons why the
 *  executable file might be covered by the GNU Public License.
 *
 *----------------------------------------------------------------------*/

#include <iostream>
#include <map>
#include <initializer_list>

#include "TCPTransceiver.h"
#include "PureManager.h"
#include "PureDevice.h"
#include "PureLaserDevice.h"
#include "PureCarDevice.h"
#include "PureDriveDevice.h"

#include "PureLocalizationDevice.h"
#include "PureDriveDevice.h"
#include "PureGpsDevice.h"
#include "VirtualCrabDevice.h"

using namespace std;

/**
  This class is intended to create all the devices required from the ros parameter server.
  The instantation of the devices is on demand.

  Also facilitates iterators through the devices as pointers to the base class PureDevice.
*/

class Configuration {
public:
  struct DeviceInfo
  {
    int notification_period;
    PureDevice* device;
  };

private:
  PureManager* pure_manager_;
  ros::NodeHandle* node_;
  ros::NodeHandle param_node_;  
  typedef std::map<std::string, DeviceInfo> Map;
  Map devices_;
public:
  typedef Map::const_iterator const_iterator;
  typedef Map::iterator iterator;

  /**
    Constructor for the configuration of all the devices.  The parameters are those used to create the devices.
    @param[in] pm The PureManager that will be used by all the devices created from this configuration
    @param[in] n The NodeHandle that will be used by all the devices created from this configuration
    */
  Configuration(PureManager* pm, ros::NodeHandle* n);

  /**
    Destructor.  Also destroy all the devices' instances.
    */
  ~Configuration();

  /**
    @return The number of correctly instantiated and configured devices
    */
  unsigned int size() const;

  /**
    @return A constant iterator to the begining of the devices set
    */
  const_iterator begin() const;

  /**
    @return A iterator to the begining of the devices set
    */
  iterator begin();

  /**
    @return A constant iterator to the end of the devices set
    */
  const_iterator end() const;

  /**
    @return A iterator to the end of the devices set
    */
  iterator end();

  /**
    Accessor to the devices configured

    @param[in] name The name of the device to be accessed as specified in the configuration file (@see load_device())
    @return If the name corresponds to an instantiated device, returns a pointer to it as a PureManager pointer.  Otherwise, return 0.
    */
  PureDevice* get_device(const std::string& name);

  /**
    Using the information in the ROS parameter server, instantiates a new device of type Device.
    To be instantiated, it is required a dictionary parameter with the correspondent name and the following fields
    - server: string with the name or ip of the computer where the service is running
    - device: integer that corresponds with the instance number od the service
    - topic: base name for the topics created related to this device

    Another optional integer field named "period" is read if exists and is used within the function start

    @param[in] name The name of the device to be instantiated as specified in the configuration file
    @return true if the device is succesfully instantiated and configured. Returns false otherwise.
    */
  template <class Device>
      bool load_device(const std::string& name);

  /**
    Starts all the devices instantiated and inserts the corresponding notifications considering the period parameter of each one
    */
  void start();  

};

//void load_configuration(PureManager* pure_manager, ros::NodeHandle* node, std::list<Configuration>& devices);

int main(int argc, char * argv[])
{
	ros::init(argc, argv, "rosbucar");
  ros::NodeHandle nh;
	PureManager pm;

  Configuration configuration(&pm, &nh);

  configuration.load_device<PureLaserDevice>("front_laser");
  configuration.load_device<PureLaserDevice>("back_laser");
  configuration.load_device<PureLaserDevice>("ground_laser");
  configuration.load_device<PureGpsDevice>("gps");
  configuration.load_device<PureLocalizationDevice>("localization");
  configuration.load_device<PureCarDevice>("car");
  configuration.load_device<PureDriveDevice>("drive");

 // std::cout << "Created " << configuration.size() << " devices" << std::endl;

  PureDevice::setTestMode(false);

  configuration.start();

  //pcd.enableJoystick(5,1000);



  //
  //	std::vector<std::string> a;
  //	a.push_back("FL");
  //	a.push_back("FR");
  //	a.push_back("FS");
  //	a.push_back("RL");
  //	a.push_back("RR");
  //	a.push_back("RS");
  //	a.push_back("Pan");
  //	a.push_back("Tilt");
  //
  //	PureDriveDevice pd(&pm,&nh,"192.168.1.2",2,a);

  //	PureGpsDevice pgd(&pm,&nh,"192.168.1.3",3,"gps");

  //	VirtualCrabDevice vcd(&pm,&nh,"192.168.1.2",2,"crab");

  //	if (pgd.start()){
  //		pgd.insertNotification(1);
  //	}
  //

  //	if (pd.start()){
  //		pd.insertNotification(1);
  //		pd.addTrigger(6);
  //		pd.addTrigger(7);
  //		pd.addTrigger(2);
  //		pd.addTrigger(5);
  //	}
  //

  /*	if (vcd.start()){
		vcd.insertNotification(10);
		vcd.enableJoystick(5,1000);
		vcd.setType(2);
	}
*/	ros::spin();
    std::cerr << "Disconnecting devices... please wait" << std::endl;

}


inline Configuration::Configuration(PureManager* pm, ros::NodeHandle* n):
    pure_manager_(pm),
    node_(n),
    param_node_("~")
{}


Configuration::~Configuration()
{
  for (iterator device_it = begin(); device_it != end(); ++device_it)
    delete device_it->second.device;
}

template <class Device>
    bool Configuration::load_device(const std::string& name) {
  DeviceInfo out;
  XmlRpc::XmlRpcValue dictionary;  
  if (param_node_.getParam(name, dictionary))
  {
    if(dictionary.hasMember("server") and dictionary.hasMember("device") and dictionary.hasMember("topic"))
    {
      int device_id = dictionary["device"];
      out.device = new Device(pure_manager_, node_, dictionary["server"], device_id, dictionary["topic"]);
      if (dictionary.hasMember("period"))
        out.notification_period = dictionary["period"];
      else
        out.notification_period = -1;
      devices_.insert(std::make_pair(name, out));      
      ROS_INFO("%s found and configured", name.c_str());
      return true;
    } else
      ROS_ERROR("%s bad configuration: Required fields are server, device and topic", name.c_str());
    return false;
  } else
  {
    ROS_INFO("%s not found", name.c_str());
    return false;
  }
}

void Configuration::start() {
  for (iterator device_it = begin(); device_it != end(); ++device_it)
  {
    DeviceInfo& configuration = device_it->second;
    PureDevice* device = configuration.device;
    if (device->start() and configuration.notification_period >= 0)
      device->insertNotification(configuration.notification_period);
  }
}

inline PureDevice* Configuration::get_device(const std::string& name)
{
  iterator it = devices_.find(name);
  return  it == devices_.end()? 0: it->second.device;
}

inline unsigned int Configuration::size() const
{
  return devices_.size();
}

inline Configuration::const_iterator Configuration::begin() const
{
  return devices_.begin();
}

inline Configuration::iterator Configuration::begin()
{
  return devices_.begin();
}

inline Configuration::const_iterator Configuration::end() const
{
  return devices_.end();
}

inline Configuration::iterator Configuration::end()
{
  return devices_.end();
}

