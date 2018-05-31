/*
 * motor.cpp
 *
 * Created: 10/05/2018 19:25:37
 *  Author: Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "motor.h"

//////////////
/// Motors ///
//////////////
Motion::Motors::Motors(MotorPosition* motorPosition, unsigned char numMotors)
{
	unsigned char motor = 0;
	MotorInfoStruct motorInfo[numMotors];

	for (motor = 0; motor < numMotors; motor++)
	{
		switch (motorPosition[motor])
		{
			case Left :
			SetMotorInfo(&motorInfo[motor], Motion::Left, Motion::TC2);
			break;
			case Right :
			SetMotorInfo(&motorInfo[motor], Motion::Right, Motion::TC0);
			break;
		}

		switch (motorInfo[motor].pwmPin)
		{
			case TC0 :
			InitializeTC0();
			break;
			case TC1 :
			InitializeTC1();
			break;
			case TC2 :
			InitializeTC2();
			break;
		}
	}

	_numMotors = numMotors;
	_motorInfo = motorInfo;
}

void Motion::Motors::InitializeTC0()
{
	// Set pins as digital outputs.
	DDRD |= (1 << DDD6) | (1 << DDD5);
	
	// Set timer to Phase Correct PWM. Top 0xFF.
	// Mode is defined by the combination of the Waveform Generation mode bits and Compare Output mode
	TCCR0A = 0;
	TCCR0B = 0;
	TCCR0A |= (1 << WGM00);
	
	// Set PWM to inverted.
	TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << COM0B1) | (1 << COM0B0);
	
	// Set prescalar to (¡8
	TCCR0B |= (1 << CS01);
}

void Motion::Motors::InitializeTC1()
{
	// Set pins as digital outputs.
	DDRB |= (1 << DDB2) | (1 << DDB1);
	
	// TODO
}

void Motion::Motors::InitializeTC2()
{
	// Set pins as digital outputs.
	DDRB |= (1 << DDB3);
	DDRD |= (1 << DDD3);
	
	// Set timer to Phase Correct PWM. Top 0xFF.
	// Mode is defined by the combination of the Waveform Generation mode bits and Compare Output mode
	TCCR2A = 0;
	TCCR2B = 0;
	TCCR2A |= (1 << WGM20);
	
	// Set PWM to inverted.
	TCCR2A |= (1 << COM2A1) | (1 << COM2A0) | (1 << COM2B1) | (1 << COM2B0);
	
	// Set prescalar to (¡8
	TCCR2B |= (1 << CS21);
}

void Motion::Motors::SetSpeed(int* speed)
{
	bool forward = 0;

	for (int motor = 0; motor < _numMotors; motor++)
	{
		forward = CapSpeed(&speed[motor]);

		switch (_motorInfo[motor].pwmPin)
		{
			case TC0 :
			SetTC0Speed(speed[motor], forward);
			break;
			case TC1 :
			SetTC1Speed(speed[motor], forward);
			break;
			case TC2 :
			SetTC2Speed(speed[motor], forward);
			break;
		}
	}
}

bool Motion::Motors::CapSpeed(int* speed)
{
	bool forward = true;

	if (*speed < 0)
	{
		forward = false;
		*speed = -*speed;
	}

	if (*speed > 255)
	{
		*speed = 255;
	}

	return forward;
}

void Motion::Motors::SetMotorInfo(MotorInfoStruct* motorInfo, MotorPosition motorPosition, PWMPin pwmPin)
{
	motorInfo->motorPosition = motorPosition;
	motorInfo->pwmPin = pwmPin;
}

/////////////////////
/// MotorsComplex ///
/////////////////////
Motion::MotorsComplex::MotorsComplex(MotorPosition* motorPosition, unsigned char numMotors)
	: Motion::Motors::Motors(motorPosition, numMotors)
{
}

void Motion::MotorsComplex::SetTC0Speed(unsigned char speed, bool forward)
{
	if (forward)
	{
		OCR0B = 0;
		OCR0A = speed;
	}
	else
	{
		OCR0B = speed;
		OCR0A = 0;
	}
}

void Motion::MotorsComplex::SetTC1Speed(unsigned char speed, bool forward)
{
	
}

void Motion::MotorsComplex::SetTC2Speed(unsigned char speed, bool forward)
{
	if (forward)
	{
		OCR2B = 0;
		OCR2A = speed;
	}
	else
	{
		OCR2B = speed;
		OCR2A = 0;
	}
}


