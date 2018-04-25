#include "Pins.h"

unsigned char qtra_pins[] =
{
  #if defined(QTRA_SENSOR_0_PIN) && !defined (QTRA_SENSOR_1_PIN) && !defined (QTRA_SENSOR_2_PIN) && !defined (QTRA_SENSOR_3_PIN) && !defined (QTRA_SENSOR_4_PIN) && !defined (QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_0_PIN
  #elif defined(QTRA_SENSOR_0_PIN)
    QTRA_SENSOR_0_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_1_PIN) && !defined (QTRA_SENSOR_2_PIN) && !defined (QTRA_SENSOR_3_PIN) && !defined (QTRA_SENSOR_4_PIN) && !defined (QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_1_PIN
  #elif defined(QTRA_SENSOR_1_PIN)
    QTRA_SENSOR_1_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_2_PIN) && !defined (QTRA_SENSOR_3_PIN) && !defined (QTRA_SENSOR_4_PIN) && !defined (QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_2_PIN
  #elif defined(QTRA_SENSOR_2_PIN)
    QTRA_SENSOR_2_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_3_PIN) && !defined (QTRA_SENSOR_4_PIN) && !defined (QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_3_PIN
  #elif defined(QTRA_SENSOR_3_PIN)
    QTRA_SENSOR_3_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_4_PIN) && !defined (QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_4_PIN
  #elif defined(QTRA_SENSOR_4_PIN)
    QTRA_SENSOR_4_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_5_PIN) && !defined (QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_5_PIN
  #elif defined(QTRA_SENSOR_5_PIN)
    QTRA_SENSOR_5_PIN,
  #endif

  #if defined(QTRA_SENSOR_6_PIN) && !defined (QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_6_PIN
  #elif defined(QTRA_SENSOR_6_PIN)
    QTRA_SENSOR_6_PIN,
  #endif
  
  #if defined(QTRA_SENSOR_7_PIN)
    QTRA_SENSOR_7_PIN,
  #endif
  
};

QTRSensorsAnalog qtra(qtra_pins, QTRA_SENSOR_EMITTER_PIN);
