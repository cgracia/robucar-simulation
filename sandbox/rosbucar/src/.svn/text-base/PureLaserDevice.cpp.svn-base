/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureLaserDevice.cpp
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

#include "PureLaserDevice.h"
#include "PureDevice.h"
#include "PureFrame.h"

PureLaserDevice::PureLaserDevice(PureManager * pm, ros::NodeHandle * nh,
		std::string server, unsigned device, std::string topic_name) :
		PureDevice(pm, nh, server, device, topic_name) {
}

bool PureLaserDevice::connect() {
	rxSize = 0;
	int res = request(ActionCode.GET, device, rxBuff, rxSize);
	if (res == 0){
                PureLaserServiceResponse * r = (PureLaserServiceResponse *) rxBuff;
                //std::cout << topic_name << ": " << r->x_coordinate << " " << r->y_coordinate << " " << r->orientation << " " << r->number_of_echoes << std::endl;
                //fprintf(stderr,"echoes %d, x_coord: %f\n",r->number_of_echoes,r->x_coordinate);
		param = *r;
		return true;
	} else {
    request_error(res, ActionCode.GET);
		return false;
	}
}


PureLaserDevice::~PureLaserDevice() {
}

void PureLaserDevice::rxLoop() {
	long long ts;

	sensor_msgs::LaserScan scan;
	scan.ranges.resize(param.number_of_echoes);
	scan.intensities.resize(param.number_of_echoes);
        scan.range_max = 80.0; //TODO: put range max as a parameter
	scan.range_min = 0.0;

	int idx = 0;
	while (keep_running) {
                //std::cerr << "Reading PURE data" << std::endl;

		if (readNotification(ts, rxBuff, rxSize)) {
			PureLaserOutboundNotification * p =
					(PureLaserOutboundNotification *) rxBuff;

			float max_angle = -1e6, min_angle = 1e6;
			for (int i = 0; i < param.number_of_echoes; i++) {
				if (p->readings[i].angle > max_angle) {
					max_angle = p->readings[i].angle;
				}
				if (p->readings[i].angle < min_angle) {
					min_angle = p->readings[i].angle;
				}
				scan.ranges[i] = p->readings[i].distance;
				scan.intensities[i] = 1.0;

				//fprintf(stderr, "%f %f\n", p->readings[i].angle, p->readings[i].distance);
			}

                        scan.angle_max = max_angle;
                        scan.angle_min = min_angle;
			scan.angle_increment = (max_angle - min_angle)
					/ (float) param.number_of_echoes;
			scan.scan_time = ts;
			scan.header.stamp = getTimestamp(ts);
      scan.header.frame_id = topic_name;
			scan.header.seq = idx++;
			if (ros::ok()) {
				p1.publish(scan);
			}
		}
	}
}

void PureLaserDevice::callback(
		const boost::shared_ptr<std_msgs::Float64 const> & message) {
        //std::cerr << "Write Notification data" << std::endl;
	txSize = 0;
	writeNotification(txBuff, txSize);
}

void PureLaserDevice::createTopics() {
	p1 = nh->advertise<sensor_msgs::LaserScan>(topic_name + "/out", 100, false);
//	s1 = nh->subscribe(topic_name + "/in", 1000, &PureLaserDevice::callback,
//			this);
}

