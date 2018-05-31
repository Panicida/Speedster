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
	Motion::MotorPosition motorPosition = Motion::Left;
	Motion::MotorsComplex motor(&motorPosition, 1);
	
	pot.EmittersOn();
    while (1) 
    {
		unsigned int potValue = 0;
		int speed = 0;
		
		pot.Read(&potValue);
		
		speed = (int)potValue;
		
		motor.SetSpeed(&speed);
    }
}

