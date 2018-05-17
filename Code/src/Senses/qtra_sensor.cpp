/*
 * QTRA_Sensor.cpp
 *
 * Created: 01/05/2018 13:11:40
 *  Author: Javier Rodriguez Posada
 */ 

#include <avr/io.h>

#include "QTRA_Sensor.h"


Senses::QTRASensor::QTRASensor(unsigned char* sensorPins, unsigned char numSensors, unsigned char numSamplesPerSensor)
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
	
	// Sensors pins mask
	portMask = 0;
	for(currentPin = 0; currentPin < numSensors; currentPin++)
	{
		this->sensorPins[currentPin] = sensorPins[currentPin];
		portMask |= (1 << sensorPins[currentPin]);
	}
	
	// Do not mask ADC6 and ADC7
	portMask &= ~(1 << ADC6_PIN) & ~(ADC7_PIN);
	
	// Configure ADC settings. Prescalar set to 156kHz
	ADCSRA |= (1 << ADEN)| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
	// Set emitter pin to output.
	DDRD |= (1 << DDD7);
	
	// Turn off the emitter
	EmittersOff();
}

void Senses::QTRASensor::ReadRaw(unsigned int* sensorValues)
{
	unsigned char sumplesDone = 0;
	unsigned char currentSensor = 0;
	
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
	DDRC &= ~portMask;
	PORTC &= ~portMask;
	
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
}

void Senses::QTRASensor::Read(unsigned int* sensorValues)
{
	unsigned char sensor = 0;
	
	ReadRaw(sensorValues);
	
	for (sensor = 0; sensor < numSensors; sensor++)
	{
		// old range: [A-B]
		// new range: [C-D]
		// Y = (X-A)/(B-A) * (D-C) + C
		sensorValues[sensor] = ((sensorValues[sensor] - calibrationMessures[sensor][0]) / (calibrationMessures[sensor][1] - calibrationMessures[sensor][0])) * 999;
	}
}

unsigned int Senses::QTRASensor::ReadLine(unsigned int* sensorValues, bool whiteLine)
{
	unsigned int result = 0;
	unsigned int sum = 0;
	unsigned char sensor;

	Read(sensorValues);

	// For loop is repeated to increase speed.
	if (whiteLine)
	{
		for (sensor = 0; sensor < numSensors; sensor++)
		{
			sensorValues[sensor] = 1000 - sensorValues[sensor];
			result = sensorValues[sensor] * (sensor + 1 );
			sum += sensorValues[sensor];
		}
	}
	else
	{
		for (sensor = 0; sensor < numSensors; sensor++)
		{
			result = sensorValues[sensor] * (sensor + 1 );
			sum += sensorValues[sensor];
		}
	}
	
	result /= sum; 

	return result;
}

void Senses::QTRASensor::EmittersOff()
{
	PORTD &= ~(1<<DDD7);
}

void Senses::QTRASensor::EmittersOn()
{
	PORTD |= (1<<DDD7);
}

void Senses::QTRASensor::Calibrate()
{
	for (int sensor = 0; sensor < numSensors; sensor++)
	{
		unsigned char sensorValues[numSensors];
		unsigned char sumplesDone = 0;
		unsigned char currentSensor = 0;
		
		calibrationMessures 
		
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
		DDRC &= ~portMask;
		PORTC &= ~portMask;
		
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
	}
}