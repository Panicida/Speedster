/*
 * 
 */
#pragma once

#include <QTRSensors.h>

//// Comment-out to use enable Pololu QTRA sensors array
#define QTRA_SENSOR
#ifdef QTRA_SENSOR
  //// Comment-out to use emitter
  //#define QTRA_SENSOR_USE_EMITTER
  
  //// Comment-out the sensors you want to use
  #define QTRA_SENSOR_0
  #define QTRA_SENSOR_1
  #define QTRA_SENSOR_2
  #define QTRA_SENSOR_3
  #define QTRA_SENSOR_4
  #define QTRA_SENSOR_5
  #define QTRA_SENSOR_6
  #define QTRA_SENSOR_7

  //// Total number of IR sensors. This number have to match with the number of sensors enable.
  #define QTRA_SENSOR_NUM 8

  //// Total number of samples for each read.
  #define IR_SENSORS_NUM_SAMPLES 5

  #include "Configuration_QTRASensor.h"
#endif

#include "Pins.h"
