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
#include "Communication/SerialData.h"

#define BAUDRATE 9600
#define WAIT_TIME 1000

int main(void)
{
	Communication::Serial serial(BAUDRATE);
	
	Communication::SerialData data("water_my_friend");
	
	for (int i=0;i<10;i++)
	{
		serial.Send(data.Data);
		_delay_ms(100);
	}
	data.FreeMemory();
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
	
}