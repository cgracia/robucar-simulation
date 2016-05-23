/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureManager.h
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

#ifndef PUREMANAGER_H_
#define PUREMANAGER_H_
#include <queue>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include "TCPTransceiver.h"
#include <semaphore.h>
#include "PureFrame.h"


struct buffElement {
	unsigned signup_id, size, address, port;
	char data[1500];
};

class Subscriber {
public:
	unsigned address, device, port, requestId;
	sem_t sem_rx;
	pthread_mutex_t mtx;
	std::queue<buffElement> srxBuff;

	Subscriber() {
		address = 0;
		device = 0;
		requestId = 0;
		sem_init(&sem_rx, 0, 0);
		pthread_mutex_init(&mtx,0);
	}

	void notification(buffElement be) {
		pthread_mutex_lock(&mtx);
		srxBuff.push(be);
		pthread_mutex_unlock(&mtx);
		sem_post(&sem_rx);
	}

	int wait(){
		sem_wait(&sem_rx);
		return 0;
	}

	int timedWait(){
		timespec timeout;
		clock_gettime(CLOCK_REALTIME,&timeout);
		timeout.tv_sec += 1;
		return sem_timedwait(&sem_rx,&timeout);
	}

	buffElement & front(){
		pthread_mutex_lock(&mtx);
		return srxBuff.front();
	}

	void pop(){
		srxBuff.pop();
		pthread_mutex_unlock(&mtx);
	}

};

class PureManager {
	TCPTransceiver tcp;
	boost::thread txTh, rxTh,dsTh;
	sem_t sem_tx, sem_rx;
	unsigned char requestId;
	std::vector<Subscriber> subscribers;
	std::queue<buffElement> txBuff,rxBuff;
	sem_t sems[0xff];
	pthread_mutex_t mtx_tx,mtx_rx,mtx_disp;
	void rxLoop();
	void txLoop();
	bool keep_running;
public:
	PureManager();
	virtual ~PureManager();
	int signup(unsigned device, std::string ctrl, unsigned port = 60000);
	int request(unsigned signup_id, unsigned int target, unsigned char action, char * data, unsigned & size);
	bool readNotification(unsigned signup_id, long long & timestamp, char * data, unsigned & size);
	unsigned char getRequestId();
	void dispatch();
	bool writeNotification(unsigned signup_id, char * data, unsigned size);
	void stop();

};

#endif /* PUREMANAGER_H_ */
