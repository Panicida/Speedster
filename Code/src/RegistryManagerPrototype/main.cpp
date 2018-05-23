/*
 * RegistryManagerPrototype.cpp
 *
 * Created: 23/05/2018 12:52:17
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "RegistryManager/IORegistry.h"

int main(void)
{
	RegistryManager::IORegistry::SetOutput(1);
	RegistryManager::IORegistry::SetInput (1);
	RegistryManager::IORegistry::SetLow(1);
	RegistryManager::IORegistry::SetHigh(1);
	RegistryManager::IORegistry::IsHigh(1);

    /* Replace with your application code */
    while (1)
    {
    }
}

