/*
 * Speedster.cpp
 *
 * Created: 29/04/2018 21:59:23
 * Author : Javier Rodriguez Posada
 */

#define F_CPU 20000000
#include <avr/io.h>
#include <util/delay.h>
#include "Senses/QTRA_Sensor.h"
#include "Pololu/Time/OrangutanTime.h"

int main(void)
{
	DDRD |= (1<<DDD1);
	PORTD &= ~(1<<PORTD7);
	
	unsigned char sensor_pins[] = {ADC0_PIN,ADC1_PIN};
	Senses::QTRASensor qtra_sensor(sensor_pins,2,5);
	
    /* Replace with your application code */
    while (1) 
    {
		unsigned int values[2] = {0,0};
		qtra_sensor.Read(values);
		PORTD |= (1<<PORTD1);
		OrangutanTime::delayMilliseconds(values[0]);
		PORTD &= ~(1<<PORTD1);
		OrangutanTime::delayMilliseconds(values[1]);
    }
}