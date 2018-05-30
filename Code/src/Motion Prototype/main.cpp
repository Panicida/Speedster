/*
 * Motion Prototype.cpp
 *
 * Created: 10/05/2018 20:29:00
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "Motion/motor.h"

// Comment out one of the following to select test mode
#define TEST_TC0
//#define TEST_TC1
//#define TEST_TC2
//#define TEST_TC0_AND_TC2

// Comment out to move backwards
#define FORWARD

#define SPEED 100

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
		Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Right, Motion::TC2);
		struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo };
		Motion::MotorsComplex motors(motorsInfo, 1);
	#elif TEST_TC0_AND_TC2
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
	motors.SetSpeed(speed);
	
    while (1) 
    {
    }
}

