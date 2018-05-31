/*
 * Motion Prototype.cpp
 *
 * Created: 10/05/2018 20:29:00
 * Author : Javier Rodriguez Posada
 */ 

#define F_CPU 20000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Motion/motor.h"

// Comment out one of the following to select test mode
//#define TEST_TC0
//#define TEST_TC1
//#define TEST_TC2
#define TEST_TC0_AND_TC2
//#define SPEED_TEST

#define SPEED 150
#define RUN_TIME 2000

int main(void)
{
	#if defined TEST_TC0
		Motion::MotorPosition motorsPosition[] = { Motion::Right };
		Motion::MotorsComplex motors(motorsPosition, 1);
	#elif defined TEST_TC1
		Motion::MotorPosition motorsPosition[] = { Motion::Right };
		Motion::MotorsComplex motors(motorsPosition, 1);
	#elif defined TEST_TC2
		Motion::MotorPosition motorsPosition[] = { Motion::Left };
		Motion::MotorsComplex motors(motorsPosition, 1);
	#else
		Motion::MotorPosition motorsPosition[] = { Motion::Right, Motion::Left };
		Motion::MotorsComplex motors(motorsPosition, 2);
	#endif
	
	int speed[] = { SPEED, SPEED };
		
	#ifdef SPEED_TEST
		_delay_ms(RUN_TIME);
	#endif
	
	motors.SetSpeed(speed);
	
	#ifdef SPEED_TEST
		_delay_ms(RUN_TIME);
		speed[0] = 0;
		speed[1] = 0;
		motors.SetSpeed(speed);
	#endif
	
    while (1) 
    {
    }
}

