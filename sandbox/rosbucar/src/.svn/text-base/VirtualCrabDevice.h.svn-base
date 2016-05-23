/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/VirtualCrabDevice.h
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

#ifndef VIRTUALCRABDEVICE_H_
#define VIRTUALCRABDEVICE_H_
#include "PureDriveDevice.h"
#include "rosbucar/CarLikeCmd.h"
#include "rosbucar/CarLikeInfo.h"

class VirtualCrabDevice : public PureDriveDevice {
	int type;
	enum {
		RR = 4, FR = 1, FL = 0, RL = 3, FS = 2, RS = 5, PAN = 6, TILT = 7
	};
	ros::Publisher p1;
	ros::Subscriber s1;
	void applyCarConfig(const rosbucar::CarLikeCmd & message);
public:
	VirtualCrabDevice(PureManager * pm, ros::NodeHandle * nh, std::string server, unsigned device, std::string topics_name);
	VirtualCrabDevice();
	virtual ~VirtualCrabDevice();
	virtual void publish(PureDriveOutboundNotification * pon, long long ts);
	void callback(const rosbucar::CarLikeCmd & message);
	virtual void createTopics();
	void setType(int type);
	virtual void joyMovement(SixAxes message);
	virtual void watchDog();
};

#endif /* VIRTUALCRABDEVICE_H_ */
