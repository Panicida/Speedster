/*
 * Motion Prototype.cpp
 *
 * Created: 10/05/2018 20:29:00
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "Motion/motor.h"

int main(void)
{
	//struct Motion::MotorInfoStruct leftMotorInfo;
	struct Motion::MotorInfoStruct rightMotorInfo;
	
	//Motion::Motors::SetMotorInfo(&leftMotorInfo, Motion::Left, Motion::TC0);
	Motion::Motors::SetMotorInfo(&rightMotorInfo, Motion::Left, Motion::TC0);
	//Motion::Motors::SetMotorInfo(&leftMotorInfo, Motion::Right, Motion::TC2);
	//struct Motion::MotorInfoStruct motorsInfo[] = { leftMotorInfo };
	struct Motion::MotorInfoStruct motorsInfo[] = { rightMotorInfo };
	//struct Motion::MotorInfoStruct motorsInfo[] = { leftMotorInfo, rightMotorInfo };
	
	Motion::MotorsComplex motors(motorsInfo, 1);
	
	motors.SetDirection(false);
	
    while (1) 
    {
		// For some reason this line break the program.
		//Read(&speed);
		Motion::MotorSpeedStruct motorSpeed;
		motorSpeed.speed = 50;
		motorSpeed.pwmPin = Motion::TC0;
		motors.SetSpeed(&motorSpeed);
    }
}

