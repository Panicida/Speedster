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
//#define TEST_TC0_AND_TC2
#define SPEED_TEST

// Comment out to move backwards
#define FORWARD

#define SPEED 150
#define RUN_TIME 2000

int main(void)
{
	#if defined TEST_TC0
		struct Motion::MotorInfoStruct rightMotorInfo;
		Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Right, Motion::TC0);
		struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo };
		Motion::MotorsComplex motors(motorsInfo, 1);
	#elif defined TEST_TC1
		struct Motion::MotorInfoStruct rightMotorInfo;
		Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Right, Motion::TC1);
		struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo };
		Motion::MotorsComplex motors(motorsInfo, 1);
	#elif defined TEST_TC2
		struct Motion::MotorInfoStruct rightMotorInfo;
		Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Left, Motion::TC2);
		struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo };
		Motion::MotorsComplex motors(motorsInfo, 1);
	#else
		struct Motion::MotorInfoStruct rightMotorInfo, leftMotorInfo;
		Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Right, Motion::TC0);
		Motion::Motors::SetMotorInfo(&leftMotorInfo, Motion::Left, Motion::TC2);
		struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo, leftMotorInfo };
		Motion::MotorsComplex motors(motorsInfo, 2);
	#endif
	
	#if defined FORWARD
		motors.SetDirection(true);
	#else
		motors.SetDirection(false);
	#endif
	
	unsigned char speed[] = { SPEED, SPEED };
		
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

