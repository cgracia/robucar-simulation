/*------------------------------------------------------------------------
 *---------------------           RosbuCar              --------------------
 *------------------------------------------------------------------------
 *                                                         V1.0B  14/09/11
 *
 *
 *  File: ./src/PureFrame.h
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


#ifndef PUREFRAME_H_
#define PUREFRAME_H_

enum PureServices {
	BATTERY = 0x400D, CAR = 0x4003, DIFFERENTIAL = 0x4005, DRIVE = 0x4009
};

struct PureHeader {
	unsigned char identifier;
};

struct PureRequest {
	unsigned char identifier;
	unsigned char action;
	unsigned short target;
	char data[0];
}__attribute__ ((__packed__));

struct PureActionCode{
	enum {
		GET = 0x00,
		QUERY = 0x01,
		REPLACE = 0x02,
		UPDATE = 0x03,
		INSERT = 0x04,
		DELETE = 0x05
	};
};

struct PureNotificationEntry {
	unsigned short target;
	unsigned char periods;
}__attribute__ ((__packed__));

struct PureDeleteNotificationEntry {
	unsigned short target;
}__attribute__ ((__packed__));

struct PureResponse {
	unsigned char identifier;
	unsigned char action;
	unsigned short target;
	unsigned char result;
	char data[0];
}__attribute__ ((__packed__));

struct PureInboundNotification {
	unsigned char identifier;
	unsigned short target;
	char data[0];
}__attribute__ ((__packed__));

struct PureOutboundNotification {
	unsigned char identifier;
	unsigned short source;
	long long timestamp;
	char data[0];
}__attribute__ ((__packed__));


#endif /* PUREFRAME_H_ */
