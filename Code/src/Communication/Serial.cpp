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
#include <avr/interrupt.h>
#include <stddef.h>
#include "Serial.h"

#define _array_lenght(type) ((char *)(&type+1)-(char*)(&type))


// Initializes static variables
unsigned int Communication::Serial::_dataSize = 0;
unsigned int Communication::Serial::_bytePosition = 0;
unsigned char* Communication::Serial::_sendBuffer = NULL;

Communication::Serial::Serial(unsigned int baudrate)
{
	unsigned long ubrr = 0;
	
	cli();
	
	// Calculate UBRRn value for the desired baudrate
	ubrr = (F_CPU / (16UL * baudrate)) - 1;
	
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	// Set frame format: 8data, 2stop bit, no parity
	UCSR0C = (1<<USBS0) |(3<<UCSZ00);
	
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	sei();
}

void Communication::Serial::Send(unsigned char* data)
{
	// Wait for the previous message to finish sending.
	while(!Communication::Serial::IsBufferEmpty());
	
	// Load message into the send buffer.
	Communication::Serial::_dataSize = _array_lenght(data);
	Communication::Serial::_bytePosition = 0;
	Communication::Serial::_sendBuffer = data;
	
	Communication::Serial::EnableTxInterrupt();
}

void Communication::Serial::EnableTxInterrupt()
{
	UCSR0B |= (1 << UDRIE0);
}

void Communication::Serial::DisableTxInterrupt()
{
	UCSR0B &= ~(1 << UDRIE0);
}

void Communication::Serial::SendWithInterrupts()
{
	// Put data into buffer, sends the data
	if (Communication::Serial::_bytePosition < Communication::Serial::_dataSize)
	{
		UDR0 = Communication::Serial::_sendBuffer[Communication::Serial::_bytePosition];
		Communication::Serial::_bytePosition++;
	}
	else
	{
		Communication::Serial::DisableTxInterrupt();
		Communication::Serial::_sendBuffer = NULL;
	}
}

bool Communication::Serial::IsBufferEmpty()
{
	return Communication::Serial::_sendBuffer == NULL;
}

ISR(USART_UDRE_vect)
{
	Communication::Serial::SendWithInterrupts();
}