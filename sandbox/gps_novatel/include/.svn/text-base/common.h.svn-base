/** \file common.h
 * \brief GPSNovatel node
 *
 * Description
 * 
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
 * \version 0.1
 * \date 2011
***********************************************/



#ifndef COMMON_H
#define COMMON_H


typedef unsigned char UChar;
typedef short int Short;
typedef unsigned short int UShort;
typedef long int Long;
typedef unsigned long int ULong;
typedef Long Enum;
typedef Long GPSec;

enum PORTS          {ALL_PORTS = 8, COM1 = 32, COM2 = 64, COM3 = 96,
                     THISPORT = 192};
enum TRIGGER        {ONNEW = 0,  ONCHANGED, ONTIME, ONNEXT, ONCE, ONMARK};
enum HOLD           {NOHOLD = 0, HOLD};

enum IDCOMANDOS     {LOG = 1, UNLOGALL = 38, FIX = 44};
enum IDMENSAJES     {RTCAOBS = 6, RTCA1 = 10, RTCAREF = 11, BESTPOS = 42, RTCAEPHEM = 347};

enum SOLUTIONSTATUS {SOL_COMPUTED = 0, INSUFFICIENT_OBS, NO_CONVERGENCE,
                     SINGULARITY, COV_TRACE, TEST_DIST, COLD_START,
                     V_H_LIMIT, VARIANCE, RESIDUALS, DELTA_POS, NEGATIVE_VAR,
                     INTEGRITY_WARNING = 13};

enum TYPE          {NONE = 0, AUTO = 1, HEIGHT = 2, POSITION = 3, VELOCITY = 4, PENDING = 18, 
                     INVALID_FIX = 19};



typedef struct {
   char      sync[3];
   UChar     longitudCabecera;
   UShort    mensajeID;
   char      tipoMensaje;
   char      direccionPuerto;
   UShort    longitudMensaje;
   UShort    secuencia;
   char      tiempoLibre;
   char      estadoTiempo;
   UShort    semana;
   GPSec     milisegundos;
   ULong     estadoRecepcion;
   UShort    reservado;
   UShort    versionSoftware;
} Cabecera;

typedef struct{
   Enum      respuestaID;
   char *    mensajeError;
} Respuesta;

typedef struct {
   Enum      port;
   UShort    mensajeID;
   char      tipoMensaje;
   char      reservado;
   Enum      trigger;
   double    periodo;
   double    offset;
   Enum      hold;
} LogCommand;

typedef struct {
   Enum      puerto;
   Enum      reservado;
} UnLogCommand;

typedef struct {
   Enum      type;
   double    param1;
   double    param2;
   double    param3;
} FixCommand;

typedef struct {
   Enum      sol_status;
   Enum      pos_type;
   double    lat, lon, alt;
   float     ondulacion;
	Enum		 datum_id;
   float     sigmaLat, sigmaLon, sigmaAlt;
   char      baseID[4];
   float     diff_age, sol_age;
   UChar     nObs, nGPSL1, nL1, nL2;
   char      reservado[4];
} BestPosLog;


#endif
