/*
 * Speedster.cpp
 *
 * Created: 29/04/2018 21:59:23
 * Author : Javier Rodriguez Posada
 */

#define F_CPU 20000000
#define BAUDRATE 9600
#define BUFFER_SIZE 256

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Senses/QTRA_Sensor.h"
#include "Communication/Serial.h"

#define TEST_RAW
//#define TEST_CALIBRATION

int main(void)
{
	int i = 0;
	unsigned int dataSize = 0;
	char buffer[BUFFER_SIZE];
	Communication::Serial serial(BAUDRATE, BUFFER_SIZE);
	
	unsigned int sensorValues[6] = {0, 0, 0, 0, 0, 0};
	unsigned char sensor_pins[] = { ADC1_PIN, ADC2_PIN, ADC3_PIN, ADC4_PIN, ADC5_PIN, ADC6_PIN };
	Senses::QTRASensor qtra_sensor(sensor_pins,6,5);
	
#ifdef TEST_CALIBRATION
	//// Calibration
	qtra_sensor.Calibrate();
	
	//// Print calibration values
	unsigned short** minMax = qtra_sensor.GetCalibrationMessures();
	for (i=0; i<6; i++)
	{
		dataSize = sprintf(buffer,"Sensor %i: [%i] | [%i]\n", i, minMax[i][0], minMax[i][1]);
		serial.Send(buffer,dataSize);
	}
#endif


	
	
	
    /* Replace with your application code */
    while (1) 
    {
		#ifdef TEST_RAW
			qtra_sensor.ReadRaw(sensorValues);
			dataSize = sprintf(buffer,"%i | %i | %i | %i | %i | %i\n", sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], sensorValues[5]);
			serial.Send(buffer,dataSize);
			_delay_ms(100);
		#endif
    }
}