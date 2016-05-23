/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDriveDevice.h
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

#ifndef PUREDriveDEVICE_H_
#define PUREDriveDEVICE_H_

#include "PureDevice.h"
#include <ros/ros.h>
#include "rosbucar/DriveCmd.h"
#include "rosbucar/DriveInfo.h"

class PureDriveDevice: public PureDevice {
	protected:
	struct PureDriveProperties {
		unsigned char type;
		unsigned char default_mode;
		float max_pos;
		float min_pos;
		float max_speed;
		float min_speed;
		float max_acceleration;
		float max_torque;
		float min_torque;
	}__attribute__ ((__packed__));

	struct PureDriveServiceResponse{
		int number_of_drives;
		PureDriveProperties drives[0];
	}__attribute__ ((__packed__));

	struct PureDriveState{
		unsigned char control_mode;
		unsigned char status;
		float value;
		float pos;
		float speed;
		float torque;
	}__attribute__ ((__packed__));

	struct PureDriveOutboundNotification {
		PureDriveState state[0];
	}__attribute__ ((__packed__));

	struct PureDriveCommand{
		unsigned char enabled;
		unsigned char control_mode;
		float value;
	}__attribute__ ((__packed__));

	struct PureDriveInboundNotification {
		PureDriveCommand command[0];
	}__attribute__ ((__packed__));

	PureDriveProperties *param;
	PureDriveCommand *commands;
	ros::Publisher *p;
	ros::Subscriber *s;
	//PureDriveInboundNotification * ibn;

	PureDriveCommand * driveCommandStatus ;
	unsigned number_of_drives;
	std::vector<std::string> topics_name;
	std::vector<int> triggers;
	int topics_name_length;
	bool single;
public:
	PureDriveDevice(PureManager * pm, ros::NodeHandle * nh, std::string server,
			unsigned device, std::vector<std::string> topics_name);
	PureDriveDevice(PureManager * pm, ros::NodeHandle * nh,
			std::string server, unsigned device,
			std::string topic_name);
	virtual ~PureDriveDevice();
	virtual void rxLoop();
	bool connect();
	virtual void createTopics();
	//void callback(const boost::shared_ptr<rosbucar::DriveCmd const> & message);
	void callback(const boost::shared_ptr<rosbucar::DriveCmd const> & message, int i);
	void addTrigger(int idx);
	void clearTriggers();
	void freeMemory();
	virtual void publish(PureDriveOutboundNotification * pon, long long ts);

};

#endif
