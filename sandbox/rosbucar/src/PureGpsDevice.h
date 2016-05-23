/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureGpsDevice.h
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

#ifndef PUREGpsDEVICE_H_
#define PUREGpsDEVICE_H_

#include "PureDevice.h"
#include <ros/ros.h>
#include "rosbucar/CarLikeCmd.h"
#include "rosbucar/CarLikeInfo.h"
#include "gps_novatel/NovatelInfo.h"
#include <sensor_msgs/NavSatFix.h>

class PureGpsDevice: public PureDevice {
	struct PureGpsServiceResponse {
		double x_antenna;
		double y_antenna;
	}__attribute__ ((__packed__));

	struct PureGpsOutboundNotification {
		enum GpsMode{INVALID, SPS, DSPS, PPS, FIXED_RTK,FLOAT_RTK, ESTIMATED, MANUAL_INPUT, SIMULATOR, WAAS};
		double lat;
		double lon;
		double alt;
		unsigned char gps_mode;
		int number_of_satellites;
		unsigned long long gps_time;
	}__attribute__ ((__packed__));

	PureGpsServiceResponse param;
    ros::Publisher pub_novatel_info, pub_gps_info;
	ros::Subscriber s1,s2;

    int8_t translateStatus(unsigned char gps_mode) const;

public:
	PureGpsDevice(PureManager * pm, ros::NodeHandle * nh, std::string server,
			unsigned device, std::string topic_name);
	virtual ~PureGpsDevice();
	virtual void rxLoop();
	bool connect();
	void createTopics();
};

#endif