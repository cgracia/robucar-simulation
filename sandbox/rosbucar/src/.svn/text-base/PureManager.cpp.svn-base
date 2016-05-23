/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureManager.cpp
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

#include "PureManager.h"
#include <vector>
#include <semaphore.h>
#include <iostream>
#include <boost/thread.hpp>
#include <time.h>

#include <ros/ros.h>

PureManager::PureManager() : tcp(0) {
    sem_init(&sem_tx, 0, 0);
    sem_init(&sem_rx, 0, 0);
    for (int i = 0; i < 0xff; i++){
        sem_init(&sems[i],0,0);
    }
    pthread_mutex_init(&mtx_rx,0);
    pthread_mutex_init(&mtx_tx,0);

    keep_running = true;
    rxTh = boost::thread(boost::bind(&PureManager::rxLoop, this));
  txTh = boost::thread(boost::bind(&PureManager::txLoop, this));
  dsTh = boost::thread(boost::bind(&PureManager::dispatch, this));

}

PureManager::~PureManager() {
    stop();
}

void PureManager::stop() {
    keep_running = false;
    rxTh.join();
    txTh.join();
    dsTh.join();
}

int PureManager::signup(unsigned device, std::string ctrl, unsigned port) {
    Subscriber su;
    su.address = inet_network(ctrl.c_str());
    su.port = port;
    su.device = device;
    subscribers.push_back(su);
    return (subscribers.size() - 1);
}

void PureManager::rxLoop() {
    while (keep_running) {
        buffElement be;
        int res = tcp.receive(be.data, be.address, be.port);
        if(res >=0){
            be.size = res;
            pthread_mutex_lock(&mtx_rx);
            rxBuff.push(be);
            //std::cerr << "RXLOOP queue elements: " << rxBuff.size() << std::endl;
            pthread_mutex_unlock(&mtx_rx);
            sem_post(&sem_rx);
        }
    }
}

void PureManager::dispatch() {
    while (keep_running) {
        timespec timeout;
        clock_gettime(CLOCK_REALTIME,&timeout);
        timeout.tv_sec += 1;
        int res = sem_timedwait(&sem_rx,&timeout);
        if (res == 0){
            pthread_mutex_lock(&mtx_rx);
            buffElement & be = rxBuff.front();
            PureHeader * ph = (PureHeader *) be.data;
            if (ph->identifier == 0 || ph->identifier == 0xFF){
                bool found = false;
                PureOutboundNotification * pon = (PureOutboundNotification *) be.data;
                for (unsigned i = 0; i < subscribers.size();i++){
                    Subscriber & su =subscribers.at(i);
                    //fprintf(stderr,"add1 %d add2 %d port1 %d port2 %d dev %d sou %d\n",su.address,htonl(be.address),su.port,be.port,su.device,pon->source);
                    if (su.address == htonl(be.address) && su.device == pon->source){
                        //std::cerr << "NOTIFING " << i << std::endl;
                        su.notification(be);
                        found = true;
                    }
                }
                if (! found){
                    ROS_WARN_STREAM("*** Warning Active Unused Notification ::" << be.address << "::0x" << pon->source);
                    //std::cerr << "*** Warning Active Unused Notification ::" << be.address << "::0x" << pon->source << std::endl;
                }
                rxBuff.pop();
                pthread_mutex_unlock(&mtx_rx);

            } else{
                PureResponse * pr = (PureResponse *) be.data;
                pthread_mutex_unlock(&mtx_rx);
                sem_post(&sems[pr->identifier]);
            }
        }
    }
}

void PureManager::txLoop() {
    while (keep_running) {
        timespec timeout;
        clock_gettime(CLOCK_REALTIME,&timeout);
        timeout.tv_sec += 1;
        int res = sem_timedwait(&sem_tx,&timeout);
        if (res == 0){
            pthread_mutex_lock(&mtx_tx);


            buffElement & be = txBuff.front();
            //std::cerr << "TXLOOP = " << be.size <<std::endl;

            //std::cerr << "Send message:" << std::endl;
            //for (unsigned int i=0; i< be.size ; ++i)
              //  std::cerr << std::hex << (int)be.data[i] << ":";
            //std::cerr << std::endl;
            tcp.send(be.data, be.size, be.address, be.port);
            txBuff.pop();

            pthread_mutex_unlock(&mtx_tx);
        }
    }
}

int PureManager::request(unsigned signup_id, unsigned int target ,unsigned char action, char * data, unsigned & size) {
    buffElement be;
    be.address = subscribers.at(signup_id).address;
    be.port = subscribers.at(signup_id).port;
    be.signup_id = signup_id;
    be.size = size + sizeof(PureRequest);

    /* protejo tb el getRequestId poniendolo aqui */
    pthread_mutex_lock(&mtx_tx);

    unsigned char rid = getRequestId();
    PureRequest * p = (PureRequest *) be.data;
    p->action = action;
    p->target = target;
    p->identifier = rid;
    memcpy(p->data, data, size);

    //std::cerr << "Enqueue request -> requestId: " << (int) rid << std::endl;
    txBuff.push(be);
    pthread_mutex_unlock(&mtx_tx);
    sem_post(&sem_tx);

    timespec timeout;
    clock_gettime(CLOCK_REALTIME,&timeout);
    timeout.tv_sec += 1;
    int res = sem_timedwait(&sems[rid],&timeout);

    if (res == 0){
        pthread_mutex_lock(&mtx_rx);
        be = rxBuff.front();
        PureResponse * pr = (PureResponse *) be.data;
        size = be.size - sizeof(PureResponse);
        //fprintf(stderr,"Id:%d act:%d target:%d result:%d size:%d\n",pr->identifier,pr->action,pr->target,pr->result,size);
        memcpy(data, be.data+sizeof(PureResponse), size);
        rxBuff.pop();
        pthread_mutex_unlock(&mtx_rx);
        return pr->result;
    } else{
        ROS_WARN_STREAM("NO VALID RESPONSE (TIMEOUT) id:" << (int) rid);
        //std::cerr << "NO VALID RESPONSE (TIMEOUT) id:" << (int) rid << std::endl;
        return -1;
    }

}

bool PureManager::writeNotification(unsigned signup_id, char * data, unsigned  size){
    buffElement be;
    PureInboundNotification * ibn = (PureInboundNotification * ) be.data;

    be.address = subscribers.at(signup_id).address;
    be.port = subscribers.at(signup_id).port;
    be.signup_id = signup_id;
    be.size = size + sizeof(PureInboundNotification);

    ibn->target = subscribers.at(signup_id).device;
    ibn->identifier = 0xFF;

    memcpy(ibn->data,data,size);

    pthread_mutex_lock(&mtx_tx);
    txBuff.push(be);
    pthread_mutex_unlock(&mtx_tx);
    sem_post(&sem_tx);

    return true;
}

bool PureManager::readNotification(unsigned signup_id, long long & timestamp, char * data, unsigned & size) {
    if (subscribers.at(signup_id).timedWait()==0){

        buffElement & be = subscribers.at(signup_id).front();

        PureOutboundNotification * pon = (PureOutboundNotification *) be.data;

        size = be.size - sizeof(PureOutboundNotification);
        memcpy(data, pon->data, size);
        timestamp = pon->timestamp;
        //std::cerr << "Read Notification  "<< pon->timestamp << std::endl;

        subscribers.at(signup_id).pop();
        return true;
    }else{
        return false;
    }
}

unsigned char PureManager::getRequestId() {
    requestId++;
    if (requestId == 0 || requestId == 0xff) {
        requestId = 1;
    }
    return requestId;
};

