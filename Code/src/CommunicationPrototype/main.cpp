/*
 * CommunicationPrototype.cpp
 *
 * Created: 31/05/2018 19:29:16
 * Author : Javier Rodriguez Posada
 */ 

#define F_CPU 20000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Communication/Serial.h"

#define BAUDRATE 9600
#define WAIT_TIME 1000
#define BUFFER_SIZE 256

int main(void)
{
	Communication::Serial serial(BAUDRATE, BUFFER_SIZE);
	
	int number = 5000;
	unsigned int dataSize = 0;
	char aux[BUFFER_SIZE];
	dataSize = sprintf(aux,"Be water my friend: %d", number);
	
	for (int i=0;i<10;i++)
	{
		serial.Send(aux,dataSize);
		_delay_ms(100);
	}
	
    /* Replace with your application code */
    while (1)
    {
		
    }
	
}