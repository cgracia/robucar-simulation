/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureLaserDevice.h
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

#ifndef PURELASERDEVICE_H_
#define PURELASERDEVICE_H_

#include "PureDevice.h"
#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/LaserScan.h>

class PureLaserDevice: public PureDevice {

	struct PureLaserServiceResponse{
		float x_coordinate;
		float y_coordinate;
    float orientation;
		int number_of_echoes;
	}__attribute__ ((__packed__));

	struct PureLaserEcho{
		float angle;
		float distance;
	}__attribute__ ((__packed__));

	struct PureLaserOutboundNotification{
		PureLaserEcho readings[0];
	}__attribute__ ((__packed__));


	PureLaserServiceResponse param;
	ros::Publisher p1;
	ros::Subscriber s1;

public:
	PureLaserDevice(PureManager * pm,ros::NodeHandle * nh,std::string server, unsigned device, std::string topic_name);
	virtual void callback(const boost::shared_ptr<std_msgs::Float64 const> & message);
	virtual ~PureLaserDevice();
	virtual void rxLoop();
	bool connect();
	void createTopics();
};

#endif /* PUREDIFFDEVICE_H_ */
