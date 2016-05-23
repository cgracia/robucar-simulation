/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureCarDevice.h
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

#ifndef PURECarDEVICE_H_
#define PURECarDEVICE_H_

#include "PureDevice.h"
#include <ros/ros.h>
#include "rosbucar/CarLikeCmd.h"
#include "rosbucar/CarLikeInfo.h"
//#include "rosbucar/CarLikeSrv.h"
#include "sensor_msgs/Joy.h"

#include <sensor_msgs/Joy.h>

class PureCarDevice: public PureDevice {
	struct PureCarServiceResponse {
		float max_speed;
		float min_speed;
		float max_steering;
		float min_steering;
		float max_acceleration;
		float max_deceleration;
		float distance_between_axes;
	}__attribute__ ((__packed__));

	struct PureCarOutboundNotification {
		enum Status {
			DISABLED, ENABLED, ERROR
		};
                //unsigned char status;
		float target_speed;
		float current_speed;
		float target_steering;
		float current_steering;
	}__attribute__ ((__packed__));

	struct PureCarInboundNotification {
		enum Action {
			ENABLE, DISABLE
		};
		unsigned char action;
		float target_speed;
		float target_steering;
	}__attribute__ ((__packed__));
	PureCarInboundNotification p;
	PureCarServiceResponse param;
	PureCarInboundNotification pinb;
  ros::Publisher p1;
	ros::Subscriber s1,s2;
	ros::ServiceServer srv1;
public:
	PureCarDevice(PureManager * pm, ros::NodeHandle * nh, std::string server,
			unsigned device, std::string topic_name);
	virtual ~PureCarDevice();
	virtual void rxLoop();
	bool connect();
	void createTopics();
	void callback(const rosbucar::CarLikeCmd & message);
//	bool serviceCallback(rosbucar::CarLikeSrv::Request & req, rosbucar::CarLikeSrv::Response & resp);
	virtual void watchDog();
	void joyMovement(sensor_msgs::Joy & message);
	virtual void hfLoop();
	void deviceSpecificConfig();
        ros::Time last_command_;
        ros::Duration watchdog_time_;
};

#endif
