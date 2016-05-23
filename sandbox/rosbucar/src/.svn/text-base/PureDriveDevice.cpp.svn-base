/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDriveDevice.cpp
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

#include "PureDriveDevice.h"
#include "PureDevice.h"
#include "PureFrame.h"
#include <sstream>

PureDriveDevice::PureDriveDevice(PureManager * pm, ros::NodeHandle * nh,
		std::string server, unsigned device,
		std::vector<std::string> topics_name) :
		PureDevice(pm, nh, server, device, "Drive") {
	this->topics_name = topics_name;
	single = true;

}
PureDriveDevice::PureDriveDevice(PureManager * pm, ros::NodeHandle * nh,
		std::string server, unsigned device,
		std::string topic_name) :
		PureDevice(pm, nh, server, device, topic_name) {
	single = true;
}

bool PureDriveDevice::connect() {
	rxSize = 0;
	p = NULL;
	s = NULL;
	param = NULL;
	driveCommandStatus = NULL;

	int res = request(ActionCode.GET, device, rxBuff, rxSize);

	if (res == 0) {
		PureDriveServiceResponse * r = (PureDriveServiceResponse *) rxBuff;
		number_of_drives = r->number_of_drives;

		fprintf(stderr, "Number of Drives %d\n", number_of_drives);
		if (!single){
			if (topics_name.size() != number_of_drives) {
                            ROS_WARN_STREAM("Incorrect Number of topic names. Should be : "
                                            << number_of_drives << " instead of " << topics_name.size());
                                //std::cerr << "Incorrect Number of topic names. Should be : "
                                //		<< number_of_drives << " instead of " << topics_name.size()
                                //		<< std::endl;
				return false;
			}
		}else{
			for (unsigned i = 0; i< number_of_drives; i++){
				std::ostringstream oss;
				oss << topic_name << "/" << i;
				topics_name.push_back(topic_name);
			}
		}

		driveCommandStatus = new PureDriveCommand[number_of_drives];
    memset(driveCommandStatus, 0, number_of_drives * sizeof(PureDriveCommand));

		param = new PureDriveProperties[number_of_drives];
		for (unsigned i = 0; i < number_of_drives; i++) {
			param[i] = r->drives[i];
			driveCommandStatus[i].control_mode = r->drives[i].default_mode;
		}

		return true;
	} else {
		request_error(res, ActionCode.GET);
		return false;
	}
}
PureDriveDevice::~PureDriveDevice() {
	stop();
	freeMemory();
}

void PureDriveDevice::freeMemory() {
	if (param) {
		delete[] param;
	}
	if (driveCommandStatus) {
		delete[] driveCommandStatus;
	}
	if (p) {
		delete[] p;
	}
	if (s) {
		delete[] s;
	}
}

void PureDriveDevice::rxLoop() {
	long long ts;
	PureDriveOutboundNotification * pon =
			(PureDriveOutboundNotification *) rxBuff;
	while (keep_running) {
		if (readNotification(ts, rxBuff, rxSize)) {
                        //std::cerr << "Reading PURE Drive data: " << rxSize << " Bytes " << std::endl;
				publish(pon,ts);
			}
		}
	}


void PureDriveDevice::publish(PureDriveOutboundNotification * pon, long long ts) {
	rosbucar::DriveInfo cli;
	for (unsigned i = 0; i < number_of_drives; i++) {
		cli.pos = pon->state[i].pos;
		cli.speed = pon->state[i].speed;
		cli.status = pon->state[i].status;
		cli.torque = pon->state[i].torque;
		cli.value = pon->state[i].value;
		cli.header.stamp = getTimestamp(ts);
                //std::cerr << i << ": current pos: " << cli.pos << " value " << cli.value
                //		<< std::endl;
		if (ros::ok()) {
			p[i].publish(cli);
		}
	}
}

void PureDriveDevice::callback(
		const boost::shared_ptr<rosbucar::DriveCmd const> & message,
		const int i) {

	driveCommandStatus[i].control_mode = message->control_mode;
	driveCommandStatus[i].enabled = message->enabled;
	driveCommandStatus[i].value = message->value;

	if (std::find(triggers.begin(), triggers.end(), i) != triggers.end()) {
		writeNotification((char*) driveCommandStatus,
				number_of_drives * sizeof(PureDriveCommand));
                //std::cerr << "Write Notification cm:" << (int) message->control_mode
                //		<< ", en:" << (int) message->enabled << ", val:"
                //		<< message->value << std::endl;
	}
}

void PureDriveDevice::addTrigger(int idx) {
	triggers.push_back(idx);
}

void PureDriveDevice::clearTriggers() {
	triggers.clear();
}

void PureDriveDevice::createTopics() {
        //std::cerr << "Creo topics" << std::endl;
	p = new ros::Publisher[number_of_drives];
	s = new ros::Subscriber[number_of_drives];
	for (unsigned i = 0; i < number_of_drives; i++) {
		p[i] = nh->advertise<rosbucar::DriveInfo>(topics_name[i] + "/out", 100,
				false);
		s[i] = nh->subscribe<rosbucar::DriveCmd>(topics_name[i] + "/in", 1000,
				boost::bind(&PureDriveDevice::callback, this, _1, i));
	}
}

