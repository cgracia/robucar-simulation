/** \file objectInterface.cpp
 * \brief objectInterface node
 *
 * Description
 * 
 * This file is part of the RoboEarth ROS WP1 package.
 * 
 * It file was originally created for <a href="http://www.roboearth.org/">RoboEarth</a>.
 * The research leading to these results has received funding from the European Union Seventh Framework Programme FP7/2007-2013 under grant agreement no248942 RoboEarth.
 *
 * Copyright (C) 2010 by <a href=" mailto:riazuelo@unizar.es">Luis Riazuelo</a>, University of Zaragoza
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \author Luis Riazuelo
 * \version 1.0
 * \date 2010
 * \image html http://www.roboearth.org/sites/default/files/RoboEarth.org_logo.gif
 * \image latex http://www.roboearth.org/sites/default/files/RoboEarth.org_logo.gif
***********************************************/


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "gps_common/GPSFix.h"
#include "gps_common/GPSStatus.h"
#include "sensor_msgs/NavSatFix.h"
#include "gps_novatel/NovatelInfo.h"

#include "common.h"

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/poll.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>

#define TAM_BUF 1024
#define CRC32_POLYNOMIAL  0xEDB88320L

#define DEFAULT_PORT "/dev/ttyUSB0"

class GPSNovatel
{
private:

//  ros::NodeHandle nh_;

  // Publishing topic
//  ros::Publisher gps_pub;

  // GPS 
  char sol_status[64];
  char pos_type[64];
//  BestPosLog bestPos;
  int gps_fd;
  struct termios oldTerm;
  struct termios newTerm;

  unsigned char buf[TAM_BUF];
  unsigned char bufRec[TAM_BUF];
  unsigned char tiempo;
  int sizeBuf;
  int sizeBufRec;
  int lecturaValida;
  int readings;



public:

  ros::NodeHandle nh_;

  // Publishing topic
  ros::Publisher gps_pub;
  ros::Publisher gps_info_pub;

  // Time GPS data
  ros::Time data_time;


  // GPS 
  BestPosLog bestPos;


  GPSNovatel():
  gps_fd(0),
  tiempo(1),
  sizeBuf(0),
  sizeBufRec(0),
  lecturaValida(1),
  readings(0)
  {

    gps_pub = nh_.advertise<sensor_msgs::NavSatFix>("gps_data", 1000);
    gps_info_pub = nh_.advertise<gps_novatel::NovatelInfo>("gps_info", 1000);
    
    std::string port;
    std::string def_port = DEFAULT_PORT;
    nh_.param( "gps_novatel/port", port, def_port );
    
    initGps(port.c_str());

  }

  int initGps(const char * puerto) {
	int gps_baud = 9600;
	int attempt;
	int maxattempts = 5;

	ROS_INFO("Initializing GPS connection: Port (%s)...\n", puerto);
	if ((gps_fd = open(puerto, O_RDWR | O_SYNC | O_NONBLOCK, S_IRUSR | S_IWUSR))
			< 0) {
		ROS_ERROR("ERROR: open() errno:%d\n", errno);
		return 0;
	}

	if (tcflush(gps_fd, TCIFLUSH) < 0) {
		ROS_ERROR("ERROR: tcflush()\n");
		close(gps_fd);
		gps_fd = -1;
		return 0;
	}

	if (tcgetattr(gps_fd, &oldTerm) < 0) {
		ROS_ERROR("ERROR: tcgetattr()\n");
		close(gps_fd);
		gps_fd = -1;
		return 0;
	}

	bzero(&newTerm, sizeof(newTerm));

	cfmakeraw(&newTerm);

	// Permitimos el poder leer del puerto serie
	newTerm.c_cflag |= CREAD;

	if (gps_baud == 9600) {
		cfsetispeed(&newTerm, B9600);
		cfsetospeed(&newTerm, B9600);
	} else if (gps_baud == 19200) {
		cfsetispeed(&newTerm, B19200);
		cfsetospeed(&newTerm, B19200);
	} else if (gps_baud == 38400) {
		cfsetispeed(&newTerm, B38400);
		cfsetospeed(&newTerm, B38400);
	} else {
		cfsetispeed(&newTerm, B4800);
		cfsetospeed(&newTerm, B4800);
	}

	if (tcsetattr(gps_fd, TCSAFLUSH, &newTerm) < 0) {
		ROS_ERROR("ERROR: tcsetattr()\n");
		close(gps_fd);
		gps_fd = -1;
		return 0;
	}

	ROS_INFO("Serial Port Open, testing connection...\n");

	// FIN INICIALIZACION DEL PUERTO SERIE

	// Intentamos leer datos del GPS para comprobar la conexion
	for (attempt = 0; attempt < maxattempts; attempt++) {
		ROS_INFO("Trying...\n");
		logBestPos();
		if (leerSerie(104)){
		  break;
		}
	}

	if (attempt == maxattempts) {
		finalizarLogs();
		tcsetattr(gps_fd, TCSADRAIN, &oldTerm);
		close(gps_fd);
		gps_fd = -1;
		return 0;
	}
	ROS_INFO("Connection OK.\n");
	return 1;
  }

void logBestPos() {

	Cabecera header;
	LogCommand log;
	unsigned long crc32;
	unsigned char * ptr;

	header.sync[0] = 0xAA;
	header.sync[1] = 0x44;
	header.sync[2] = 0x12;

	header.longitudCabecera = sizeof(Cabecera);
	header.mensajeID = LOG;
	header.tipoMensaje = 0;
	header.direccionPuerto = THISPORT;
	header.longitudMensaje = sizeof(LogCommand);
	header.secuencia = 0;
	header.tiempoLibre = 0;
	header.estadoTiempo = 0;
	header.semana = 0;
	header.milisegundos = 0;
	header.estadoRecepcion = 0;
	header.reservado = 0;
	header.versionSoftware = 0;

	log.port = THISPORT;
	log.mensajeID = BESTPOS;
	log.tipoMensaje = 0;
	log.reservado = 0;
	log.trigger = ONTIME;
	log.periodo = tiempo;
	log.offset = 0.0;
	log.hold = 0;

	ptr = buf;
	bcopy((void *) &header, (void *) ptr, sizeof(Cabecera));
	sizeBuf = sizeof(Cabecera);
	ptr += sizeBuf;

	bcopy((void *) &log, (void *) ptr, sizeof(LogCommand));
	sizeBuf += sizeof(LogCommand);

	crc32 = CalculateBlockCRC32(sizeBuf, buf);

	ptr = buf + sizeBuf;

	bcopy((void *) &crc32, (void *) ptr, sizeof(long));
	sizeBuf += sizeof(float);

	enviar();
}

void finalizarLogs() {
	Cabecera header;
	UnLogCommand unLog;
	unsigned long crc32;
	unsigned char * ptr;

	header.sync[0] = 0xAA;
	header.sync[1] = 0x44;
	header.sync[2] = 0x12;

	header.longitudCabecera = sizeof(Cabecera);
	header.mensajeID = UNLOGALL;
	header.tipoMensaje = 0;
	header.direccionPuerto = /*THISPORT*/COM1;
	header.longitudMensaje = sizeof(UnLogCommand);
	header.secuencia = 0;
	header.tiempoLibre = 0;
	header.estadoTiempo = 0;
	header.semana = 0;
	header.milisegundos = 0;
	header.estadoRecepcion = 0;
	header.reservado = 0;
	header.versionSoftware = 0;

	unLog.puerto = ALL_PORTS;
	unLog.reservado = 0;

	sizeBuf = sizeof(Cabecera);
	ptr = buf;
	bcopy((void *) &header, (void *) ptr, sizeof(Cabecera));

	ptr += sizeBuf;
	bcopy((void *) &unLog, (void *) ptr, sizeof(UnLogCommand));
	sizeBuf += sizeof(UnLogCommand);

	crc32 = CalculateBlockCRC32(sizeBuf, buf);

	ptr = buf + sizeBuf;

	bcopy((void *) &crc32, (void *) ptr, sizeof(long));
	sizeBuf += sizeof(float);

	enviar();
}

int leerSerie(int rsize) {
	bool synced = false;
	char bufAux[TAM_BUF];
	int size = 3, bytesLeidos = 0;

	while (!synced) {
		if (timed_read(gps_fd, &bufAux[0], 1) < 0) {
			return 0;
		} else {
			if ((unsigned char) bufAux[0] != 0xaa) {
				continue;
			}
		}

		if (timed_read(gps_fd, &bufAux[1], 1) < 0) {
			return 0;
		} else {
			if ((unsigned char) bufAux[1] != 0x44) {
				continue;
			}
		}

		if (timed_read(gps_fd, &bufAux[2], 1) < 0) {
			return 0;
		} else {
			if ((unsigned char) bufAux[2] != 0x12) {
				continue;
			}
		}
		synced = 1;
	}
	do {
		bytesLeidos = timed_read(gps_fd, (void*) (bufAux + size), sizeof(bufRec));
		if (bytesLeidos < 0) {
			ROS_ERROR("Error Reading serial port\n");
			return 0;
		} else {
			size += bytesLeidos;
		}
	} while (size < rsize);

	bcopy((const void *) bufAux, (void *) bufRec, size);
	sizeBufRec = size;
	readings ++ ;
        data_time = ros::Time::now();
	return 1;
}

void enviar() {
	int i = 0, enviado = 0;
	tcflush(gps_fd, TCIOFLUSH);
	while (sizeBuf > 0) {
		enviado = write(gps_fd, (const char*) (buf + i), sizeBuf);
		if (enviado >= 0) {
			i += enviado;
			sizeBuf -= enviado;
		}
	}
}

unsigned long CRC32Value(int i) {
	int j;
	unsigned long crc;
	crc = i;
	for (j = 8; j > 0; j--) {
		if (crc & 1)
			crc = (crc >> 1) ^ CRC32_POLYNOMIAL;
		else
			crc >>= 1;
	}
	return crc;
}

unsigned long CalculateBlockCRC32(unsigned int size, unsigned char * buffer) {
	unsigned long temp1, temp2, crc = 0;

	while (size-- != 0) {
		temp1 = (crc >> 8) & 0x00FFFFFFL;
		temp2 = CRC32Value(((int) crc ^ *buffer++) & 0xff);
		crc = temp1 ^ temp2;
	}
	return crc;
}

int timed_read(int rx, void * buff, int size){
	int r = 0, timeout = 2000;
	struct timeval tv;
	if (timeout > 0) {
		fd_set fd_rx;
		tv.tv_sec = 0;
		tv.tv_usec = 1000 * timeout;

		FD_ZERO(&fd_rx);
		FD_SET(rx, &fd_rx);

		r = select(FD_SETSIZE, &fd_rx, NULL, NULL, &tv);
	} else {
		r = 1;
	}
	if (r>0) {
		return read(rx,buff,size);
	}else{
		fprintf(stderr,"timeout\n");
		return -1;
	}
}

int analizaPaquete() {
	Cabecera header;
	Respuesta respuesta;

	unsigned long crc32, crc32Rec;
//	int huso;
//	double x, y;
//	GeoUTM::Hemisferio h;

	sizeBufRec -= sizeof(float);

	crc32 = CalculateBlockCRC32(sizeBufRec, bufRec);
	bcopy((void *) (bufRec + sizeBufRec), (void *) &crc32Rec, sizeof(long));

	if (crc32 != crc32Rec) {
		ROS_ERROR("GPS >>> CRC no valido %lu  %lu %d\n", crc32, crc32Rec,
				sizeBufRec);
		return 1;
	}
	lecturaValida = 1;
	// Si mensaje es una respuesta => \0 al final del string de respuesta
	bufRec[sizeBufRec] = 0;

	bcopy((void *) bufRec, (void *) &header, sizeof(Cabecera));
	sizeBufRec = sizeof(Cabecera);

	// Si mensaje leido es una respuesta
	if (header.tipoMensaje & 0x80) {
		bcopy((void *) (bufRec + sizeBufRec), (void *) &respuesta.respuestaID,
				sizeof(Enum));
		sizeBufRec += sizeof(Enum);
		respuesta.mensajeError = (char *) (bufRec + sizeBufRec);
		ROS_DEBUG("GPS >>> %s\n", respuesta.mensajeError);
		return 0;
	}

	// Mensaje es un log de BestPos

//	pthread_mutex_lock(&mtx);
	bcopy((void *) (bufRec + sizeBufRec), (void *) &bestPos, sizeof(BestPosLog));

/*	if (hayHuso) { // Ya conocemos el huso
		geoUTM->setGeograficas(bestPos.lon, bestPos.lat);
		geoUTM->geo2UTM_Huso();
	} else {
		geoUTM->setGeograficas(bestPos.lon, bestPos.lat);
		geoUTM->geo2UTM();
		hayHuso = true;
	}

	geoUTM->getUTM(x, y, huso, h);

	lastx = x;
	lasty = y;
	lastz = bestPos.alt;
	pthread_mutex_unlock(&mtx);
*/
	/* SAME as DIFFERENCE
	 double resPx, resPy, resTh;
	 double resPx2, resPy2, resTh2;

	 iLoc(basex, basey, 0, &resPx, &resPy, &resTh);
	 cLoc(resPx, resPy, resTh, x, y, 0, &resPx2, &resPy2, &resTh2);

	 fprintf(stderr, "deltax = %f, Deltay = %f, Delta = \n",
	 resPx2, resPy2);
	 */

	switch (bestPos.sol_status) {
		case 0:
			sprintf(sol_status, "%s", "SOL_COMPUTED");
			break;
		case 1:
			sprintf(sol_status, "%s", "INSUFFICIENT_OBS");
			break;
		case 2:
			sprintf(sol_status, "%s", "NO_CONVERGENCE");
			break;
		case 3:
			sprintf(sol_status, "%s", "SINGULARITY");
			break;
		case 4:
			sprintf(sol_status, "%s", "COV_TRACE");
			break;
		case 5:
			sprintf(sol_status, "%s", "TEST_DIST");
			break;
		case 6:
			sprintf(sol_status, "%s", "COLD_START");
			break;
		case 7:
			sprintf(sol_status, "%s", "V_H_LIMIT");
			break;
		case 8:
			sprintf(sol_status, "%s", "VARIANCE");
			break;
		case 9:
			sprintf(sol_status, "%s", "RESIDUALS");
			break;
		case 10:
			sprintf(sol_status, "%s", "DESLTA_POS");
			break;
		case 11:
			sprintf(sol_status, "%s", "NEGATIVE_BAR");
			break;
		case 12:
			sprintf(sol_status, "%s", "RESERVER");
			break;
		case 13:
			sprintf(sol_status, "%s", "INTEGRITY_WARNING");
			break;
		default:
			sprintf(sol_status, "%s", "DEFAULT");
		}
		switch (bestPos.pos_type) {
		case 0:
			sprintf(pos_type, "%s", "NONE");
			break;
		case 1:
			sprintf(pos_type, "%s", "FIXEDPOS");
			break;
		case 2:
			sprintf(pos_type, "%s", "FIXEDHEIGHT");
			break;
		case 3:
			sprintf(pos_type, "%s", "FIXEDVEL");
			break;
		case 8:
			sprintf(pos_type, "%s", "DOPPLER_VELOCITY");
			break;
		case 16:
			sprintf(pos_type, "%s", "SINGLE");
			break;
		case 17:
			sprintf(pos_type, "%s", "PSDRDIFF");
			break;
		case 18:
			sprintf(pos_type, "%s", "WAAS");
			break;
		case 20:
			sprintf(pos_type, "%s", "OMNISTAR");
			break;
		case 32:
			sprintf(pos_type, "%s", "L1_FLOAT");
			break;
		case 33:
			sprintf(pos_type, "%s", "IONOFREE_FLOAT");
			break;
		case 34:
			sprintf(pos_type, "%s", "NARROW_FLOAT");
			break;
		case 48:
			sprintf(pos_type, "%s", "L1_INT");
			break;
		case 49:
			sprintf(pos_type, "%s", "WIDE_INT");
			break;
		case 50:
			sprintf(pos_type, "%s", "NARROW_INT");
			break;
		case 51:
			sprintf(pos_type, "%s", "RTK_DIRECT_INS");
			break;
		case 52:
			sprintf(pos_type, "%s", "INS");
			break;
		case 64:
			sprintf(pos_type, "%s", "OMNISTAR_HP");
			break;
		default:
			sprintf(pos_type, "%s", "DEFAULT");
		}


	return 1;
}


};


/**
 * This node implements the access to a gps novatel.
 */

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gps_novatel");

  GPSNovatel gpsNode;

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    sensor_msgs::NavSatFix msg;
    gps_novatel::NovatelInfo msgNovatel;

    if (gpsNode.leerSerie(104)){;
      gpsNode.analizaPaquete();
      if (gpsNode.bestPos.sol_status == 0) {
        //ROS_INFO("gpsNode.bestPos.pos_type %d",gpsNode.bestPos.pos_type);
        if (gpsNode.bestPos.pos_type >= 0 && gpsNode.bestPos.pos_type <16){
          msg.status.status = -1;
          msg.status.service = 1;
          msg.position_covariance_type = 0;
        }
        if (gpsNode.bestPos.pos_type == 16){
          msg.status.status = 0;
          msg.status.service = 1;
          msg.position_covariance_type = 1;
        }
        if (gpsNode.bestPos.pos_type == 17){
          msg.status.status = 1;
          msg.status.service = 1;
          msg.position_covariance_type = 1;
        }
        if (gpsNode.bestPos.pos_type > 17){
          msg.status.status = 2;
          msg.status.service = 1;
          msg.position_covariance_type = 2;
        }
      }
      else{
        msg.status.status = -1;
        msg.status.service = 1;
      }

      //msg.header.seq
      msg.header.stamp = gpsNode.data_time;
      msg.header.frame_id = "/gps_link";

      msg.latitude =  gpsNode.bestPos.lat;
      msg.longitude =  gpsNode.bestPos.lon;
      msg.altitude =  gpsNode.bestPos.alt;
      msg.position_covariance[0] = gpsNode.bestPos.sigmaLat;
      msg.position_covariance[1] = 0.0;
      msg.position_covariance[2] = 0.0;
      msg.position_covariance[3] = 0.0;
      msg.position_covariance[4] = gpsNode.bestPos.sigmaLon;
      msg.position_covariance[5] = 0.0;
      msg.position_covariance[6] = 0.0;
      msg.position_covariance[7] = 0.0;
      msg.position_covariance[8] = gpsNode.bestPos.sigmaAlt;

    } else{
      msg.position_covariance_type = 0;
      msg.status.status = -1;
      msg.status.service = 1;
    }

    msgNovatel.header.stamp = gpsNode.data_time;
    msgNovatel.sol_status = gpsNode.bestPos.sol_status;
    msgNovatel.pos_type = gpsNode.bestPos.pos_type;
    msgNovatel.lat =  gpsNode.bestPos.lat;
    msgNovatel.lon =  gpsNode.bestPos.lon;
    msgNovatel.alt =  gpsNode.bestPos.alt;
    msgNovatel.ondulation = gpsNode.bestPos.ondulacion;
    msgNovatel.datum_id = gpsNode.bestPos.datum_id;
    msgNovatel.sigmaLat = gpsNode.bestPos.sigmaLat;
    msgNovatel.sigmaLon = gpsNode.bestPos.sigmaLon;
    msgNovatel.sigmaAlt = gpsNode.bestPos.sigmaAlt;
    msgNovatel.base_id = gpsNode.bestPos.baseID;
    msgNovatel.diff_age = gpsNode.bestPos.diff_age; 
    msgNovatel.sol_age = gpsNode.bestPos.sol_age;
    msgNovatel.nObs = gpsNode.bestPos.nObs;
    msgNovatel.nGPSL = gpsNode.bestPos.nGPSL1;
    msgNovatel.nL1 = gpsNode.bestPos.nL1;
    msgNovatel.nL2 = gpsNode.bestPos.nL2;

    gpsNode.gps_pub.publish(msg);
    gpsNode.gps_info_pub.publish(msgNovatel);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;

}










