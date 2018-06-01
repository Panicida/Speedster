/*
 * Serial.cpp
 *
 * Created: 31/05/2018 20:30:14
 *  Author: Javier Rodriguez Posada
 */ 

#ifndef F_CPU
#define F_CPU 20000000UL
#endif

#include <avr/io.h>
#include "Serial.h"

Communication::Serial::Serial(unsigned int baudrate)
{
	unsigned long ubrr = 0;
	
	// Calculate UBRRn value for the desired baudrate
	ubrr = (F_CPU / (16UL * baudrate)) - 1;
	
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	// Set frame format: 8data, 2stop bit, no parity
	UCSR0C = (1<<USBS0) |(3<<UCSZ00);
	
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
}

void Communication::Serial::Send(unsigned char data)
{
	// Wait for empty transmit buffer
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	// Put data into buffer, sends the data
	UDR0 = data;
}