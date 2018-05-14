/*
 * MotionWithSensesPrototype.cpp
 *
 * Created: 14/05/2018 21:47:20
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "Senses/qtra_sensor.h"
#include "Motion/motor.h"

int main(void)
{
	// Create sensor on ADC7, potentiometer.
	unsigned char potPin[1] = { ADC7_PIN };
	Senses::QTRASensor pot(potPin, 1, 1);
	
	// Create motor control for PWM1
	Motion::MotorInfoStruct motorInfoStruct;
	Motion::Motors::SetMotorInfo(&motorInfoStruct, Motion::Left, Motion::TC0);
	
	Motion::MotorsComplex motor(&motorInfoStruct, 1);
	
	pot.EmittersOn();
    while (1) 
    {
		unsigned int speed;
		pot.Read(&speed);
		
		Motion::MotorSpeedStruct speedStruct;
		speedStruct.pwmPin = Motion::TC0;
		speedStruct.speed = speed;
		
		motor.SetSpeed(&speedStruct);
    }
}

