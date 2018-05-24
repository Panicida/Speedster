/*
 * PidControl.cpp
 *
 * Created: 23/05/2018 20:13:39
 *  Author: Javier Rodriguez Posada
 */ 

#include "PidControl.h"

Control::PidControl::PidControl(unsigned int consigna)
{
	_consigna = consigna;
	_lastError = 0;
}

int Control::PidControl::Proportional(unsigned int currentValue)
{
	int result = 0;
	int error = 0;
	
	error = currentValue - _consigna;
	
	result = (error / 4);
	
	return result;
}

int Control::PidControl::ProportionalIntegral(unsigned int currentValue)
{
	int result = 0;
	int error = 0;
	
	error = currentValue - _consigna;
	
	result = (error / 4) + 6 * (error - _lastError);
	_lastError = error;
	
	return result;
}

void Control::PidControl::SetConsigna(unsigned int consigna)
{
	_consigna = consigna;
}

/*
void loop ()
{
	unsigned int valorSensores [4];
	
	unsigned int posicion = sensoresReflexion.readLine(valorSensores);
	
	seguirLinea (posicion);
}

void seguirLinea (int posicion)
{
	int error = posicion - 1500;
	
	int velocidadDiferencial = error / 4 + 6 * (error - ultimoError);
	ultimoError = error;
	
	int motorI = MAX_SPEED + velocidadDiferencial;
	int motorD = MAX_SPEED - velocidadDiferencial;
	
	if (motorI > MAX_SPEED)
	{
		motorI = MAX_SPEED;
	}
	if (motorD > MAX_SPEED)
	{
		motorD = MAX_SPEED;
	}
	if (motorI < -MAX_SPEED)
	{
		motorI = -MAX_SPEED;
	}
	if (motorD < -MAX_SPEED)
	{
		motorD = -MAX_SPEED;
	}
	
	velocidad(motorI,motorD);
}

*/