/*
 * Contains the pins definitions.
 */

#ifdef QTRA_SENSOR
  #ifdef QTRA_SENSOR_USE_EMITTER
    #define QTRA_SENSOR_EMITTER_PIN 2
  #else
    #define QTRA_SENSOR_EMITTER_PIN QTR_NO_EMITTER_PIN
  #endif
  
  #ifdef QTRA_SENSOR_0
    #define QTRA_SENSOR_0_PIN 0
  #endif

  #ifdef QTRA_SENSOR_1
    #define QTRA_SENSOR_1_PIN 1
  #endif
  
  #ifdef QTRA_SENSOR_2
    #define QTRA_SENSOR_2_PIN 2
  #endif
  
  #ifdef QTRA_SENSOR_3
    #define QTRA_SENSOR_3_PIN 3
  #endif
  
  #ifdef QTRA_SENSOR_4
    #define QTRA_SENSOR_4_PIN 4
  #endif
  
  #ifdef QTRA_SENSOR_5
    #define QTRA_SENSOR_5_PIN 5
  #endif
  
  #ifdef QTRA_SENSOR_6
    #define QTRA_SENSOR_6_PIN 6
  #endif
  
  #ifdef QTRA_SENSOR_7
    #define QTRA_SENSOR_7_PIN 7
  #endif
#endif // QTRA_SENSOR
