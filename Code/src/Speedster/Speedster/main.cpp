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
	
	QTRA_Sensor my_qtra_sensor = new QTRA_Sensor();
	
	int delay = 0;
	while (1)
	{
		PORTD |= (1<<PORTD1); // drive PD1 high
		my_qtra_sensor.Read(delay);
		_delay_ms((double)delay);
		PORTD &= ~(1<<PORTD1); // drive PD1 low
		_delay_ms(500);
	}
	
	/*
    
    while (1) {
	    PORTD |= (1<<PORTD1); // drive PD1 high
	    _delay_ms(100); // delay 100 ms
	    PORTD &= ~(1<<PORTD1); // drive PD1 low
	    _delay_ms(900); // delay 900 ms
    }*/
}

