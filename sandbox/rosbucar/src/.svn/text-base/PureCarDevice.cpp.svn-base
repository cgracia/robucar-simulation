/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureCarDevice.cpp
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

#include "PureCarDevice.h"
#include "PureDevice.h"
#include "PureFrame.h"

#include <nav_msgs/Odometry.h>

PureCarDevice::PureCarDevice(PureManager * pm, ros::NodeHandle * nh,
                             std::string server, unsigned device, std::string topic_name) :
    PureDevice(pm, nh, server, device, topic_name) {
}

bool PureCarDevice::connect() {
    rxSize = 0;
    int res = request(ActionCode.GET, device, rxBuff, rxSize);
    if (res == 0){
        PureCarServiceResponse * r = (PureCarServiceResponse *) rxBuff;
        //std::cout << topic_name << ": " << r->max_speed
        //          << " " << r->min_speed
        //          << " " << r->max_steering
        //          << " " << r->min_steering
        //          << " " << r->max_acceleration
        //          << " " << r->max_deceleration
        //          << " " << r->distance_between_axes << std::endl;
        //fprintf(stderr,"distance %f, max_speed: %f\n", r->distance_between_axes, r->max_speed);
        param = *r;
        return true;
    } else {
        request_error(res,ActionCode.GET);
        return false;
    }
}


PureCarDevice::~PureCarDevice() {
}

void PureCarDevice::rxLoop() {
    long long ts;
    rosbucar::CarLikeInfo cli;
    PureCarOutboundNotification * p = (PureCarOutboundNotification * ) rxBuff;
    while (keep_running) {
       // std::cerr << "Reading PURE CARLIKE data" << std::endl;
        if (readNotification(ts, rxBuff, rxSize)) {
           // std::cerr << " rxSize *********" << rxSize << std::endl;

            cli.current_speed = p->current_speed;
            cli.target_speed = p->target_speed;
            cli.current_steering = p->current_steering;
            cli.target_steering = p->target_steering;
            cli.header.stamp = getTimestamp(ts);
            //cli.status = p->status;
            //std::cerr << "current steering:" << p->current_steering
            //		<< " target:" << p->target_steering << std::endl;
            if (ros::ok()) {
                p1.publish(cli);
            }
        }
    }
}

void PureCarDevice::callback(const rosbucar::CarLikeCmd & message) {

    //std::cerr << "Write Notification data" << std::endl;
    hflock();
    pinb.action = message.action;
    pinb.target_speed = message.target_speed;
    pinb.target_steering = message.target_steering;
    hfunlock();
    ROS_INFO("Received command: %d, %f, %f", pinb.action, pinb.target_speed, pinb.target_steering);
   // fprintf(stderr,"->>>>>>>>>>>> %d %f %f\n",message.action,message.target_speed,message.target_steering);
    last_command_ = ros::Time::now();

}

void PureCarDevice::createTopics() {
    //std::cerr << "Creo topics" << std::endl;
    p1 = nh->advertise<rosbucar::CarLikeInfo>(topic_name + "/out", 100, false);
    s1 = nh->subscribe(topic_name + "/in", 1000, &PureCarDevice::callback,this);
    //	srv1 = nh->advertiseService(topic_name + "/setspeed", &PureCarDevice::serviceCallback, this );
}

void PureCarDevice::watchDog(){
    hflock();
    pinb.action = 1;
    pinb.target_speed = 0.0;
    pinb.target_steering = 0.0;
    ROS_WARN("Car Watchdog");
    hfunlock();
}

void PureCarDevice::joyMovement(sensor_msgs::Joy & message){
    hflock();
    pinb.action = message.buttons[10];
    pinb.target_speed = 0.2*message.axes[3];
    pinb.target_steering = 0.4*message.axes[2];
    hfunlock();
}

void PureCarDevice::hfLoop(){
    hflock();
    pinb.action = 0;
    pinb.target_speed = 0.0;
    pinb.target_steering = 0.0;
    hfunlock();
    while (keep_running)
    {
        ros::Duration elapsed = ros::Time::now() - last_command_;
        if (elapsed > watchdog_time_)
        {
            watchDog();
            last_command_ = ros::Time::now();
        }
        hflock();
        writeNotification((char*) &pinb, sizeof(PureCarInboundNotification));
        hfunlock();
        usleep(2500);
    }
}
/*
bool PureCarDevice::serviceCallback(rosbucar::CarLikeSrv::Request & req, rosbucar::CarLikeSrv::Response & resp){
 std::cerr << "Write Notification data" << std::endl;
 hflock();
 pinb.action = req.cmd.action;
 pinb.target_speed = req.cmd.target_speed;
 pinb.target_steering = req.cmd.target_steering;
 hfunlock();
 resp.ok = true;
 return true;
}
*/
void PureCarDevice::deviceSpecificConfig(){
    hfLoopNeeded = false;
    rxLoopNeeded = true;
    watchdog_time_ = ros::Duration(1.0);
}


