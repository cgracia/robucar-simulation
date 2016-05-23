/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/TCPTransceiver.cpp
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

#include "TCPTransceiver.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ros/ros.h>

TCPTransceiver::TCPTransceiver(in_addr_t iface) {
	if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
            ROS_FATAL("Unable to create socket");
                //perror("Create Socket");
		exit(1);
	}

	struct sockaddr_in addr;
	memset((char *) &addr, 0, sizeof(addr));
	memset((char *) &rxaddr, 0, sizeof(rxaddr));
	memset((char *) &txaddr, 0, sizeof(txaddr));

	addr.sin_port = htons(4444);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(iface);

	if (bind(sock, (const sockaddr *) &addr, sizeof(addr)) == -1){
		perror("bind");
	}
};

int TCPTransceiver::send(char * s, unsigned int size, uint32_t address, unsigned int port){

	//std::cerr << "TCP send size: " << size << std::endl;

	txaddr.sin_family = AF_INET;
	txaddr.sin_port = htons(port);
	txaddr.sin_addr.s_addr = htonl(address);
    return sendto(sock, s, size, 0, (const sockaddr *) &txaddr, sizeof(txaddr));
};

int TCPTransceiver::receive(char * s, uint32_t & address, unsigned int & port){

        //std::cerr << "TCP receive " << std::endl;
	struct timeval tv;
	fd_set fd_rx;
	tv.tv_sec = 2;
	tv.tv_usec = 0;
	FD_ZERO(&fd_rx);
	FD_SET(sock, &fd_rx);
	int r = select(FD_SETSIZE, &fd_rx, NULL, NULL, &tv);

	if (r) {
		socklen_t sl = sizeof(rxaddr);
		int res = recvfrom(sock, s, 1500, 0, (sockaddr *) & rxaddr, &sl);
		address = rxaddr.sin_addr.s_addr;
		port = rxaddr.sin_port;
		return res;
	} else{
		return -1;
	}
};

TCPTransceiver::~TCPTransceiver() {
// TODO Auto-generated destructor stub
};

