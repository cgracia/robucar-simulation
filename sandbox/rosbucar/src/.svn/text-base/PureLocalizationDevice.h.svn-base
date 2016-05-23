/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureLocalizationDevice.h
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

#ifndef PURELocalizationDEVICE_H_
#define PURELocalizationDEVICE_H_

#include <ros/ros.h>
#include "rosbucar/CarLikeCmd.h"
#include "rosbucar/CarLikeInfo.h"

#include <tf/transform_broadcaster.h>


#include "PureDevice.h"

#include <geometry_msgs/PoseWithCovarianceStamped.h>

class PureLocalizationDevice: public PureDevice {
	struct PureLocalizationServiceResponse {
		enum Status{METRIC, DECIMETRIC, CENTMETRIC, PROPRIOCEPTIVE,EXTEROCEPTIVE,ERROR};
		double x;
		double y;
		double orientation;
		int status;
	}__attribute__ ((__packed__));

	struct PureLocalizationOutboundNotification {
		enum Status{METRIC, DECIMETRIC, CENTMETRIC, PROPRIOCEPTIVE,EXTEROCEPTIVE,ERROR};
		double x;
		double y;
		double orientation;
		int status;
	}__attribute__ ((__packed__));

	struct PureLocalizationReplaceRequest{
		long long ts;
		double x;
		double y;
		double orientation;
	}__attribute__ ((__packed__));

	struct PureLocalizationUpdateRequest{
		double x;
		double y;
		double orientation;
	}__attribute__ ((__packed__));

	PureLocalizationServiceResponse param;
	ros::Publisher p1;
	ros::Subscriber s1,s2;
  tf::TransformBroadcaster tf_;

public:
	PureLocalizationDevice(PureManager * pm, ros::NodeHandle * nh, std::string server,
			unsigned device, std::string topic_name);
	virtual ~PureLocalizationDevice();
	virtual void rxLoop();
	bool connect();
	void createTopics();
  void replace(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const> & message);
  void update(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const> & message);
	void a(){
		PureLocalizationReplaceRequest p;
		std::cerr << "Write REPLACE data" << std::endl;
		p.x = 100;
		p.y = 100;
		p.orientation = 0.4;

		memcpy(rxBuff,&p,sizeof(PureLocalizationReplaceRequest));
		rxSize = sizeof(PureLocalizationReplaceRequest);
		int res = request(ActionCode.REPLACE, device, rxBuff, rxSize);
		if (res == 0){
			std::cerr << "REPLACE Localization OK" << std::endl;
		} else {
			request_error(res,ActionCode.REPLACE);
		}
	}
};

#endif
