/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDevice.h
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
#ifndef PUREDEVICE_H_
#define PUREDEVICE_H_
#include "PureManager.h"
#include <ros/ros.h>

#if ROS_VERSION_MINIMUM(1,8,7) //ros fuerte
    #include <sensor_msgs/Joy.h>
#else
    #include <joy/Joy.h>
#endif

#include <time.h>

class PureDevice {

	PureManager  * pm;
	boost::thread rxLoopTh, txLoopTh, joyLoopTh, hfLoopTh;
	unsigned signup_id;
#if ROS_VERSION_MINIMUM(1,8,7) //ros fuerte
    void joyCallback(const sensor_msgs::Joy & message);
#else
   void joyCallback(const joy::Joy & message);
#endif
	void joyLoop();
	pthread_mutex_t mtx_joy, mtx_hf;

protected:
	struct SixAxes{
		bool buttons[25];
		double axes[25];
	};
	unsigned rxSize, txSize, device;
	char rxBuff[1500],txBuff[1500],reqBuff[1500];
	bool hfLoopNeeded, rxLoopNeeded, async;
	std::string server, topic_name;
	ros::NodeHandle * nh;
	PureActionCode ActionCode;
	bool keep_running, already_stopped,notification_inserted;
	ros::Subscriber sjoy;
	SixAxes sixaxes;
	int joyButton;
	int joy_update_delay, joy_watchdog_delay;
	long long sixaxes_time;
public:
	virtual ~PureDevice();
	PureDevice(PureManager * pm, ros::NodeHandle * nh,std::string server, unsigned device, std::string topic_name);
	virtual void rxLoop();
	virtual bool connect() = 0;
	virtual void createTopics()=0;
	bool start();
	int request(unsigned char action, unsigned int target, char * data, unsigned & size);
	bool readNotification(long long & ts, char * buff, unsigned & size);
	bool writeNotification(char * data, unsigned  size);
	void request_error(int res, int action, std::string comment = "");
	int deleteNotification();
	int insertNotification(int periods);
	void stop();
	void enableJoystick(int update_delay, int watchdog_delay);
	virtual void joyMovement(SixAxes message);
	virtual void hfLoop();
	virtual void watchDog();
	void displayAndChange(boost::thread& daThread, int priority);
	ros::Time getTimestamp(long long ts);
	void hflock();
	void hfunlock();
	virtual void setPriority(int priority);
	static bool _testMode;
	virtual void deviceSpecificConfig();

	static void setTestMode(bool testMode){
		_testMode = testMode;
	}


};


/* namespace Pure */
#endif /* PUREDEVICE_H_ */
