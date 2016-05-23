/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureDevice.cpp
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

#include "PureDevice.h"
#include <boost/thread.hpp>

bool PureDevice::_testMode;

PureDevice::PureDevice(PureManager * pm, ros::NodeHandle * nh,std::string server, unsigned device, std::string topic_name){
    this->pm = pm;
    signup_id = pm->signup(device, server);
    hfLoopNeeded = rxLoopNeeded = async = false;
    this->device = device;
    this->server = server;
    this->nh = nh;
    this->topic_name = topic_name;
    this->keep_running = true;
    this->already_stopped = false;
    this->notification_inserted = false;
    pthread_mutex_init(&mtx_hf,0);
    //deleteNotification();
}

void PureDevice::hflock(){
    pthread_mutex_lock(&mtx_hf);
}
void PureDevice::hfunlock(){
    pthread_mutex_unlock(&mtx_hf);
}

bool PureDevice::readNotification(long long & ts, char * buff, unsigned & size){
    return pm->readNotification(signup_id,ts,buff,size);
}

bool PureDevice::writeNotification(char * data, unsigned size){
    return pm->writeNotification(signup_id,data,size);
}

PureDevice::~PureDevice() {
    if (!already_stopped){
        stop();
    }
}

void PureDevice::stop(){
    already_stopped = true;
    if (notification_inserted){
        deleteNotification();
    }
    keep_running = false;
    rxLoopTh.join();
    hfLoopTh.join();
}

void PureDevice::rxLoop() {

}

void PureDevice::deviceSpecificConfig(){
    rxLoopNeeded = true;
    hfLoopNeeded = false;
}

bool PureDevice::start() {
    deviceSpecificConfig();
    bool res = connect() || _testMode;
    if (res){
        createTopics();
        //std::cerr << "aqui si\n";
        if (hfLoopNeeded){
            //	std::cerr << "aqui pure \n";
            hfLoopTh = boost::thread(boost::bind(&PureDevice::hfLoop, this));
            displayAndChange(hfLoopTh,99);
        }
    }
    return res;
}

int PureDevice::request(unsigned char action, unsigned int target, char * data , unsigned & size){
    return pm->request(signup_id,target,action,data,size);
}

void PureDevice::request_error(int res, int action, std::string comment){
    std::string s1,s2;
    switch (res){
    case -1:
        s1 = "TIMEOUT";
        break;
    case 0x01:
        s1 = "UNKNOWN_TARGET";
        break;
    case 0x02:
        s1 = "ACTION_NOT_SUPPORTED";
        break;
    case 0x03:
        s1 = "UNKNOWN_ACTION";
        break;
    case 0x04:
        s1 = "INVALID_LENGTH";
        break;
    case 0x05:
        s1 = "INVALID_DATA";
        break;
    case 0x10:
        s1 = "MAXIMUM_NUMBER_OF_NOTIFICATION_REACHED";
        break;
    case 0x11:
        s1 = "ALREADY ACTIVE";
        break;
    default:
        s1="UNKNOWN ERROR::" + res;
        break;
    }

    if (comment ==""){
        ROS_WARN_STREAM("DEVICE::" << topic_name << "::" << server << "::0x0" << device << "::ACTION::" << action <<"::" << s1);
        //std::cerr << "DEVICE::" << topic_name << "::" << server << "::0x0" << device << "::ACTION::" << action <<"::" << s1 <<  std::endl;
    }else{
        ROS_WARN_STREAM("DEVICE::" << topic_name << "::" << server << "::0x0" << device << "::ACTION::" << action <<"::" << s1 <<  "::" << comment);
        //std::cerr << "DEVICE::" << topic_name << "::" << server << "::0x0" << device << "::ACTION::" << action <<"::" << s1 <<  "::" << comment <<std::endl;
    }
}

int PureDevice::deleteNotification(){
    PureDeleteNotificationEntry * pdne = (PureDeleteNotificationEntry *) reqBuff;
    pdne->target = device;
    unsigned int size = sizeof(PureDeleteNotificationEntry);
    int res = request(ActionCode.DELETE, 0x01, reqBuff, size);
    if (res == 0){
        ROS_INFO_STREAM("DEVICE::" << topic_name << "::" << server << "::0x" << device
                        << "::NOTIFICATION CORRECTLY DELETED");
        //std::cerr << "DEVICE::" << topic_name << "::" << server << "::0x" << device
        //	<< "::NOTIFICATION CORRECTLY DELETED" << std::endl;
        notification_inserted = false;
        return res;
    } else {
        request_error(res,ActionCode.DELETE);
        return res;
    }
};


int PureDevice::insertNotification(int periods){
    PureNotificationEntry  * pne = (PureNotificationEntry*) reqBuff;
    pne->target = device;
    pne->periods = periods;
    unsigned int size = sizeof(PureNotificationEntry);
    int res = request(ActionCode.INSERT, 0x01, reqBuff, size);
    if (res == 0x00 || res == 0x11 || _testMode){
        ROS_INFO_STREAM("DEVICE::" << topic_name << "::" << server << "::0x0" << device
                        << "::NOTIFICATION CORRECTLY INSERTED");
        //std::cerr << "DEVICE::" << topic_name << "::" << server << "::0x0" << device
        //	<< "::NOTIFICATION CORRECTLY INSERTED" << std::endl;

        if (rxLoopNeeded){
            rxLoopTh = boost::thread(boost::bind(&PureDevice::rxLoop, this));
            displayAndChange(rxLoopTh,1);
        }

        notification_inserted = true;
        return res;
    } else {
        request_error(res,ActionCode.INSERT);
        notification_inserted = false;
        return res;
    }
}

void PureDevice::hfLoop(){
}

void PureDevice::enableJoystick(int update_delay, int watchdog_delay){
    pthread_mutex_init(&mtx_joy,0);
    this->joy_update_delay = update_delay*1000;
    this->joy_watchdog_delay = watchdog_delay*1000;
    joyLoopTh = boost::thread(boost::bind(&PureDevice::joyLoop, this));
    sjoy = nh->subscribe("/joy", 1000, &PureDevice::joyCallback,this);
}

#if ROS_VERSION_MINIMUM(1, 8, 7) //ros fuerte
void PureDevice::joyCallback(const sensor_msgs::Joy & message) {
#else
    void PureDevice::joyCallback(const joy::Joy & message) {
#endif

    pthread_mutex_lock(&mtx_joy);
    for (unsigned i = 0; i< message.buttons.size(); i++) {
        sixaxes.buttons[i] = message.buttons[i];
        //std::cerr << "JOY CALLBACK " << i << " "<<sixaxes.buttons[i] << std::endl;

    }
    for (unsigned i = 0; i< message.axes.size(); i++) {
        sixaxes.axes[i] = message.axes[i];
    }
    pthread_mutex_unlock(&mtx_joy);

    timespec ts;
    clock_gettime(CLOCK_REALTIME,&ts);
    sixaxes_time = ts.tv_sec*1000 + ts.tv_nsec/1000000;

}


void PureDevice::joyLoop() {
   // std::cerr << "joyloop" << std::endl;
    while (keep_running) {
        timespec ts;
        clock_gettime(CLOCK_REALTIME,&ts);
        long long now = ts.tv_sec*1000 + ts.tv_nsec/1000000;
        if ( (now - sixaxes_time) < (long long) joy_watchdog_delay){

            pthread_mutex_lock(&mtx_joy);
            joyMovement(sixaxes);
            pthread_mutex_unlock(&mtx_joy);

        } else{
            watchDog();
        }
        usleep(joy_update_delay);
    }
}

void PureDevice::watchDog(){

}

void PureDevice::joyMovement(SixAxes message){

}

ros::Time PureDevice::getTimestamp(long long ts){
    /*
 ts *= 10;
 unsigned int s = ts / 1000;
 unsigned int ns = (ts % 1000)*1000000;
  */
    unsigned int s = ts / 100;
    unsigned int ns = (ts % 100)*10000000;
    ros::Time t = ros::Time(s, ns);
    return t;
}


void PureDevice::displayAndChange(boost::thread& daThread, int priority) {
    int retcode;
    int policy;

    pthread_t threadID = (pthread_t) daThread.native_handle();
    struct sched_param param;
    //std::cout << "Changing Priority for "<< topic_name << " Thread...";
    if ((retcode = pthread_getschedparam(threadID, &policy, &param)) != 0) {
        ROS_WARN("Unable to get thread priority");
        errno = retcode;
        return;
    }
   // std::cout << "ok\n";

   // std::cout << "INHERITED ("<< topic_name << ") :";
   // std::cout << "policy=" << ((policy == SCHED_FIFO) ? "SCHED_FIFO" :
     //                                                   (policy == SCHED_RR)    ? "SCHED_RR"    :
       //                                                                           (policy == SCHED_OTHER) ? "SCHED_OTHER" : "???")
         //     << ", priority=" << param.sched_priority << std::endl;

    policy = SCHED_FIFO;
    param.sched_priority = priority;

    if ((retcode = pthread_setschedparam(threadID, policy, &param)) != 0) {
        errno = retcode;
        ROS_WARN("Unable to set thread priority: %s", sys_errlist[errno]);
        //perror("pthread_setschedparam");
        //exit(EXIT_FAILURE);
    }

    //std::cout << "CHANGED   ("<< topic_name << ") :";
    //std::cout << "policy=" << ((policy == SCHED_FIFO) ? "SCHED_FIFO" :
      //                                                  (policy == SCHED_RR) ? "SCHED_RR" :
        //                                                                       (policy == SCHED_OTHER) ? "SCHED_OTHER" :
          //                                                                                               "???")<< ", priority=" << param.sched_priority << std::endl;
}

void PureDevice::setPriority(int priority){
    displayAndChange(rxLoopTh, priority);
}
