/*
 * qtra_sensor.cpp
 *
 * Created: 28/04/2018 16:03:40
 *  Author: Javier Rodriguez Posada
 */ 

#include "qtra_sensor.h"
#include <math.h>
#include <avr/io.h>

QTRA_Sensor::QTRA_Sensor()
{
	//// Save the pins configuration.
	//this->pins = pins;
	
	//// Set the pins as analog inputs.
	QTRA_Sensor::SetPins();
}

/// <sumary>
/// bit = 0 -> input, bit = 1 -> output.
/// Port C is a 7-bit port
/// </sumary>
bool QTRA_Sensor::SetPins()
{
	bool result = false;
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescalar to 128 - 125KHz sample rate @ 16MHz

	ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
	ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading

	// No MUX values needed to be changed to use ADC0

	ADCSRA |= (0 << ADATE);  // Set ADC to Free-Running Mode

	ADCSRA |= (1 << ADEN);  // Enable ADC
	ADCSRA |= (1 << ADSC);  // Start A2D Conversions
	
	PORTC = (1<<PORTC0);
	DDRC = (1<<DDC0);
	
	//DDRC &= 0b1111110;
	//PORTC |=0b0000001; 
	/*
	//// Save the current port configuration.
	int port_registry_default_value = DDRC;
	
	//// Set all pins as output
	int port_registry_value = 255;
	
	//// Restore pins that has not to be set.
	for(int i=0; i< 8; i++)
	{
		if (!this->pins[i])
		{
			pin_registry_value |= pow(2,i);
		}
	}
	
	if (port_registry_value < 256)
	{
		DDRC = port_registry_value
		result = true;
	}
	*/
	return result;
}

bool QTRA_Sensor::Read(int& values)
{
	return ADCH;
}