/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDiffDevice.h
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

#ifndef PUREDIFFDEVICE_H_
#define PUREDIFFDEVICE_H_

#include "PureDevice.h"
#include <ros/ros.h>
#include <std_msgs/Float64.h>

class PureDiffDevice: public PureDevice {

	struct PureDiffServiceResponse{
		float max_speed;
		float min_speed;
		float max_angular_speed;
		float min_angular_speed;
		float max_acceleration;
		float min_acceleration;
		float max_angular_acceleration;
		float min_angular_acceleration;
		float distance_between_wheels;
	}__attribute__ ((__packed__));

	struct PureDiffOutboundNotification{
		float target_speed;
		float current_speed;
		float target_angular_speed;
		float current_angular_speed;
	}__attribute__ ((__packed__));

	struct PureDiffInboundNotification{
		float target_speed;
		float target_angular_speed;
	}__attribute__ ((__packed__));

	PureDiffServiceResponse param;
	ros::Publisher p1;
	ros::Subscriber s1;

public:
	PureDiffDevice(PureManager * pm,ros::NodeHandle * nh,std::string server, unsigned device, std::string topic_name);
	virtual void callback(const boost::shared_ptr<std_msgs::Float64 const> & message);
	virtual ~PureDiffDevice();
	virtual void rxLoop();
	bool connect();
	void createTopics();
};

#endif /* PUREDIFFDEVICE_H_ */
