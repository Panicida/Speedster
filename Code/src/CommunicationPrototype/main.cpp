/*
 * CommunicationPrototype.cpp
 *
 * Created: 31/05/2018 19:29:16
 * Author : Javier Rodriguez Posada
 */ 

#define F_CPU 20000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Communication/Serial.h"

#define BAUDRATE 9600
#define WAIT_TIME 1000

int main(void)
{
	Communication::Serial serial(BAUDRATE);
	
	unsigned char letter = 'c';
	
    /* Replace with your application code */
    while (1) 
    {
		serial.Send(letter);
		_delay_ms(WAIT_TIME);
    }
}