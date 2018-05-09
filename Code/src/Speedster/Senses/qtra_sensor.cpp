/*
 * QTRA_Sensor.cpp
 *
 * Created: 01/05/2018 13:11:40
 *  Author: Javier Rodriguez Posada
 */ 

#include <avr/io.h>

#include "QTRA_Sensor.h"


QTRASensor::QTRASensor(unsigned char* sensorPins, unsigned char numSensors, unsigned char numSamplesPerSensor)
{
	unsigned char currentPin = 0;
	
	calibratedMinimumOn=0;
	calibratedMaximumOn=0;
	calibratedMinimumOff=0;
	calibratedMaximumOff=0;
	
	if (numSensors > QTRA_MAX_SENSORS)
	{
		this->numSensors = QTRA_MAX_SENSORS;
	}
	else
	{
		this->numSensors = numSensors;
	}
	
	this->numSamplesPerSensor = numSamplesPerSensor;
	
	portMask = 0;
	for(currentPin = 0; currentPin < numSensors; currentPin++)
	{
		this->sensorPins[currentPin] = sensorPins[currentPin];
		portMask |= (1 << sensorPins[currentPin]);
	}
	
	// Configure ADC settings. Prescalar set to 156kHz
	ADCSRA |= (1 << ADEN)| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	// Turn off the emitter
	EmittersOff();
}

void QTRASensor::Read(unsigned int* sensorValues)
{
	unsigned char sumplesDone = 0;
	unsigned char currentSensor = 0;
	
	EmittersOn();
	
	// Store current state of various registers.
	unsigned char admux = ADMUX;
	unsigned char adcsra = ADCSRA;
	unsigned char ddr = DDRD;
	unsigned char port = PORTD;
	
	// Wait for any current conversion to finish.
	while (ADCSRA & (1 << ADSC));
	
	// Reset values.
	for (currentSensor = 0; currentSensor < numSensors; currentSensor++)
	{
		sensorValues[currentSensor] = 0;
	}
	
	// Set all sensors pins to high-Z inputs
	DDRC &= ~(1 << portMask);
	PORTC &= ~(1 << portMask);
	
	for (sumplesDone = 0; sumplesDone < numSamplesPerSensor; sumplesDone++)
	{
		for (currentSensor = 0; currentSensor < numSensors; currentSensor++)
		{
			// Set analog input channel
			ADMUX = (1 << REFS0) | sensorPins[currentSensor];
			
			// Start the conversion.
			ADCSRA |= (1 << ADSC);
			
			// Wait for conversion to finish.
			while (ADCSRA & (1 << ADSC));
			
			// Add in the conversion result.
			sensorValues[currentSensor] += ADC;
		}
	}
	
	// Restore registry default values.
	ADMUX = admux;
	ADCSRA = adcsra;
	PORTD = port;
	DDRD = ddr;
	
	EmittersOff();
}

void QTRASensor::EmittersOn()
{
	PORTD &= ~(1<<DDD7);
}

void QTRASensor::EmittersOff()
{
	PORTD |= (1<<DDD7);
}