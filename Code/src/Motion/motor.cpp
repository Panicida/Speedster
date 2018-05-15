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
Motion::Motors::Motors(MotorInfoStruct* motorInfo, unsigned char numMotors)
{
	this->numMotors = numMotors;
	forward = true;
	
	for (int motor = 0; motor < numMotors; motor++)
	{
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
	
	// Set PWM to non inverted.
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1);
	
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
	
	// Set PWM to non inverted.
	TCCR2A |= (1 << COM2A1) | (1 << COM2B1);
	
	// Set prescalar to (¡8
	TCCR2B |= (1 << CS21);
}

void Motion::Motors::SetSpeed(MotorSpeedStruct* speed)
{
	for (int motor = 0; motor < numMotors; motor++)
	{
		switch (speed[motor].pwmPin)
		{
			case TC0 :
				SetTC0Speed(speed[motor].speed);
				break;
			case TC1 :
				SetTC1Speed(speed[motor].speed);
				break;
			case TC2 :
				SetTC2Speed(speed[motor].speed);
				break;
		}
	}
}

void Motion::Motors::SetMotorInfo(MotorInfoStruct* motorInfo, MotorPosition motorPosition, PWMPin pwmPin)
{
	motorInfo->motorPosition = motorPosition;
	motorInfo->pwmPin = pwmPin;
}

/////////////////////
/// MotorsComplex ///
/////////////////////
Motion::MotorsComplex::MotorsComplex(MotorInfoStruct* motorInfo, unsigned char numMotors)
	: Motion::Motors::Motors(motorInfo, numMotors)
{
}



void Motion::MotorsComplex::SetTC0Speed(unsigned char speed)
{
	if (forward)
	{
		OCR0B = 255;
		OCR0A = speed;
	}
	else
	{
		OCR0B = speed;
		OCR0A = 255;
	}
}

void Motion::MotorsComplex::SetTC1Speed(unsigned char speed)
{
	
}

void Motion::MotorsComplex::SetTC2Speed(unsigned char speed)
{
	
}

void Motion::MotorsComplex::SetDirection(bool direction)
{
	forward = direction;
}


