/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/VirtualCrabDevice.cpp
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

#include "VirtualCrabDevice.h"

VirtualCrabDevice::VirtualCrabDevice(PureManager * pm, ros::NodeHandle * nh,
		std::string server, unsigned device, std::string topics_name) :
	PureDriveDevice(pm, nh, server, device, topics_name) {
	type = 0;
}

VirtualCrabDevice::~VirtualCrabDevice() {

}

void VirtualCrabDevice::setType(int type) {
	this->type = type;
}

void VirtualCrabDevice::createTopics() {
        //std::cerr << "Creo topics" << std::endl;
	p1 = nh->advertise<rosbucar::CarLikeInfo> (topic_name + "/out", 100, false);
	s1 = nh->subscribe(topic_name + "/in", 1000, &VirtualCrabDevice::callback,
			this);
}

void VirtualCrabDevice::publish(PureDriveOutboundNotification * pon, long long ts) {
	rosbucar::CarLikeInfo cli;
	cli.current_speed = pon[FR].state[FR].speed;
	cli.current_steering = pon[FR].state[FR].pos;
	cli.target_speed = driveCommandStatus[FR].value;
	cli.target_steering = driveCommandStatus[FS].value;
	cli.status = driveCommandStatus[FR].enabled;
	cli.header.stamp = getTimestamp(ts);
	p1.publish(cli);
}
void VirtualCrabDevice::applyCarConfig(const rosbucar::CarLikeCmd & message) {
	driveCommandStatus[FR].control_mode = 1;
	driveCommandStatus[FR].enabled = message.action;
	driveCommandStatus[FR].value = message.target_speed;

	driveCommandStatus[FL].control_mode = 1;
	driveCommandStatus[FL].enabled = message.action;
	driveCommandStatus[FL].value = message.target_speed;

	driveCommandStatus[RR].control_mode = 1;
	driveCommandStatus[RR].enabled = message.action;
	driveCommandStatus[RR].value = message.target_speed;

	driveCommandStatus[RL].control_mode = 1;
	driveCommandStatus[RL].enabled = message.action;
	driveCommandStatus[RL].value = message.target_speed;

	driveCommandStatus[FS].control_mode = 0;
	driveCommandStatus[FS].enabled = message.action;
	driveCommandStatus[FS].value = message.target_steering;

	driveCommandStatus[RS].control_mode = 0;
	driveCommandStatus[RS].enabled = message.action;

	if (type == 0) {
		driveCommandStatus[RS].value = 0;
	} else if (type == 1) {
		driveCommandStatus[RS].value = message.target_steering;
	} else {
		driveCommandStatus[RS].value = -message.target_steering;
	}
}

void VirtualCrabDevice::callback(const rosbucar::CarLikeCmd & message) {
	applyCarConfig(message);
	writeNotification((char*) driveCommandStatus,
			number_of_drives * sizeof(PureDriveCommand));
}

void VirtualCrabDevice::watchDog() {
	rosbucar::CarLikeCmd a;
	a.action = 0;
	callback(a);
}

void VirtualCrabDevice::joyMovement(SixAxes message) {
	rosbucar::CarLikeCmd a;

	if (message.buttons[10] || message.buttons[8]) {
		if (message.buttons[10] && message.buttons[8]) {
			type = 1;
		} else if (message.buttons[10]) {
			type = 0;
		} else if (message.buttons[8]) {
			type = 2;
		}
		a.action = 1;
		a.target_speed = 0.2 * message.axes[3];
		a.target_steering = 0.4 * message.axes[2];
	} else {
		a.action = 0;
	}
	if (message.buttons[1]) {
		driveCommandStatus[PAN].control_mode = 0;
		driveCommandStatus[PAN].enabled = 1;
		driveCommandStatus[PAN].value = message.axes[0];
		driveCommandStatus[TILT].control_mode = 0;
		driveCommandStatus[TILT].enabled = 1;
		driveCommandStatus[TILT].value = message.axes[1];
	} else{
		driveCommandStatus[PAN].enabled = 0;
		driveCommandStatus[TILT].enabled = 0;
	}
	applyCarConfig(a);
	writeNotification((char*) driveCommandStatus, number_of_drives * sizeof(PureDriveCommand));
}

