/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDiffDevice.cpp
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
#include "PureDiffDevice.h"
#include "PureDevice.h"
#include "PureFrame.h"

PureDiffDevice::PureDiffDevice(PureManager * pm, ros::NodeHandle * nh, std::string server,
		unsigned device, std::string topic_name) :
		PureDevice(pm, nh, server, device,topic_name) {
}

bool PureDiffDevice::connect(){
	PureDiffServiceRequest req;
	rxSize = 0;
	bool res = request(req.GET, device,rxBuff, rxSize);
	//XXX
	res=true;
	if (!res) {
		std::cerr << "DIFFSERVICE::"<< server <<"::0x" << device
				<< "::Unable to get RESPONSE from PURE controller" << std::endl;
		return false;
	} else {
		PureDiffServiceResponse * r = (PureDiffServiceResponse *) rxBuff;
		param = *r;
		return true;
	}
}

PureDiffDevice::~PureDiffDevice() {
}

void PureDiffDevice::rxLoop() {
	double ts;
	while (1) {
		std::cerr << "Reading PURE data" << std::endl;
		readNotification(ts, rxBuff, rxSize);
		std_msgs::Float64 f64;
		p1.publish(f64);
	}
}

void PureDiffDevice::callback(const boost::shared_ptr<std_msgs::Float64 const> & message) {
	std::cerr << "Write Notification data" << std::endl;
	txSize = 0;
	writeNotification(txBuff, txSize);
}


void PureDiffDevice::createTopics(){
	p1 = nh->advertise<std_msgs::Float64>(topic_name+"/out",100,false);
	s1 = nh->subscribe(topic_name+"/in",1000,&PureDiffDevice::callback, this);
}

