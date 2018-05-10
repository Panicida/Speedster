/*
 * Speedster.cpp
 *
 * Created: 25/04/2018 21:51:35
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>

#define F_CPU 20000000 // AVR clock frequency in Hz, used by util/delay.h
#include <util/delay.h>

#include "configuration.h"

int main(void)
{
	DDRD |= (1<<DDD7) | (1<<DDD1); // set LED pin PD1 to output
	PORTD |= (1<<PORTD7); // drive PD1 high
	
	unsigned char line_sensor_pins[] = {ADC2_PIN,ADC3_PIN,ADC4_PIN,ADC5_PIN};
	QTRASensor line_qtra_sensor(line_sensor_pins,4,5);
	
	while (1)
	{
	}
}

