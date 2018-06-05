/*
 * SerialData.cpp
 *
 * Created: 02/06/2018 23:11:38
 *  Author: Javier Rodriguez Posada
 */ 

#include <stdlib.h>
#include "SerialData.h"

#define _array_lenght(type) ((char *)(&type+1)-(char*)(&type))

Communication::SerialData::SerialData(const char* string)
{
	AddString(string);
}

Communication::SerialData::SerialData(int number)
{
	AddNumber(number);
}

void Communication::SerialData::FreeMemory()
{
	free(Data);
}

void Communication::SerialData::AddString(const char* string)
{
	/*
	unsigned char aux[_array_lenght(string)];
	for(int i=0; i < _array_lenght(string); i++)
	{
		aux[i] = string[i];
	}
	
	Data = aux;*/
	
	Data = (unsigned char*)malloc(_array_lenght(string));
	for(int i=0; i < _array_lenght(string); i++)
	{
		Data[i] = string[i];
	}
}

void Communication::SerialData::AddNumber(int number)
{
	
}