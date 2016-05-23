/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureLocalizationDevice.cpp
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


#include "PureLocalizationDevice.h"
#include "PureDevice.h"
#include "PureFrame.h"
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>

PureLocalizationDevice::PureLocalizationDevice(PureManager * pm, ros::NodeHandle * nh,
                                               std::string server, unsigned device, std::string topic_name) :
    PureDevice(pm, nh, server, device, topic_name) {
}

bool PureLocalizationDevice::connect() {
    rxSize = 0;
    int res = request(ActionCode.GET, device, rxBuff, rxSize);
    if (res == 0){
        PureLocalizationServiceResponse * r = (PureLocalizationServiceResponse *) rxBuff;
        //fprintf(stderr,"x %f, y: %f tita:%f status:%d\n",r->x,r->y,r->orientation, r->status);
        param = *r;
        return true;
    } else {
        request_error(res,ActionCode.GET);
        return false;
    }
}


PureLocalizationDevice::~PureLocalizationDevice() {
}

void PureLocalizationDevice::rxLoop() {
    long long ts;
    geometry_msgs::PoseWithCovarianceStamped msg;
    msg.header.frame_id = "odom";

    tf::StampedTransform st;
    st.frame_id_ = "odom";
    st.child_frame_id_ = "base_link";

    PureLocalizationOutboundNotification * p = (PureLocalizationOutboundNotification * ) rxBuff;
    while (keep_running) {
        //std::cerr << "Waiting PURE Localization data" <<std::endl;
        if (readNotification(ts,rxBuff,rxSize)){
          //  std::cerr << "Reading PURE Localization data status:" << p->status << " x: "<< p->x <<std::endl;
          //  std::cerr << " rxSize *********" << rxSize << std::endl;
            msg.pose.pose.position.x = p->x;
            msg.pose.pose.position.y = p->y;
            msg.pose.pose.orientation = tf::createQuaternionMsgFromYaw(p->orientation);
            msg.header.stamp = getTimestamp(ts);

            st.stamp_ = msg.header.stamp;
            st.getOrigin()[0] = p->x;
            st.getOrigin()[1] = p->y;
            st.setRotation(tf::createQuaternionFromYaw(p->orientation));

            if (ros::ok()) {
                p1.publish(msg);
                tf_.sendTransform(st);
            }
        }
    }
}

void PureLocalizationDevice::replace(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const> & message) {
    PureLocalizationReplaceRequest p;
    std::cerr << "Write REPLACE data" << std::endl;
    p.x = message->pose.pose.position.x;
    p.y = message->pose.pose.position.y;
    p.orientation = tf::getYaw(message->pose.pose.orientation);

    memcpy(rxBuff,&p,sizeof(PureLocalizationReplaceRequest));
    rxSize = sizeof(PureLocalizationReplaceRequest);
    int res = request(ActionCode.REPLACE, device, rxBuff, rxSize);
    if (res == 0){
        std::cerr << "REPLACE Localization OK" << std::endl;
    } else {
        request_error(res,ActionCode.REPLACE);
    }
}

void PureLocalizationDevice::update(const boost::shared_ptr<geometry_msgs::PoseWithCovarianceStamped const> & message) {
    PureLocalizationUpdateRequest p;
    std::cerr << "Write UPDATE data" << std::endl;

    p.x = message->pose.pose.position.x;
    p.y = message->pose.pose.position.y;
    p.orientation = tf::getYaw(message->pose.pose.orientation);

    memcpy(rxBuff,&p,sizeof(PureLocalizationUpdateRequest));
    rxSize = sizeof(PureLocalizationUpdateRequest);
    int res = request(ActionCode.UPDATE, device, rxBuff, rxSize);
    if (res == 0){
        std::cerr << "UPDATE Localization OK" << std::endl;
    } else {
        request_error(res,ActionCode.UPDATE);
    }
}

void PureLocalizationDevice::createTopics() {
    //std::cerr << "Creo topics" << std::endl;

    p1 = nh->advertise<geometry_msgs::PoseWithCovarianceStamped>(topic_name + "/out", 100, false);
    s1 = nh->subscribe(topic_name + "/replace", 100, &PureLocalizationDevice::replace,this);
    s2 = nh->subscribe(topic_name + "/update", 100, &PureLocalizationDevice::update,this);
}


