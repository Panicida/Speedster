/*
 * Speedster.cpp
 *
 * Created: 25/04/2018 21:51:35
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "Motion/motor.h"
#include "Senses/qtra_sensor.h"
#include "Pololu/Time/OrangutanTime.h"
#include "Control/PidControl.h"

int main(void)
{
	/*************************/
	/* INITIALIZES VARIABLES */
	/*************************/
	// Create line sensor.
	unsigned char qtraSensorPins[] = { ADC3_PIN, ADC4_PIN, ADC5_PIN, ADC6_PIN };
	Senses::QTRASensor lineSensor(qtraSensorPins, 4, 5);
	
	// Create motor control.
	Motion::MotorInfoStruct motorInfoStructLeft, motorInfoStructRight;
	Motion::Motors::SetMotorInfo(&motorInfoStructLeft, Motion::Left, Motion::TC0);
	Motion::Motors::SetMotorInfo(&motorInfoStructRight, Motion::Right, Motion::TC2);
	Motion::MotorInfoStruct motorInfoStruct[] = { motorInfoStructLeft , motorInfoStructRight };
	Motion::MotorsComplex motorControl(motorInfoStruct, 2);
	
	// Create control
	Control::PidControl control(2000);
	
	/*************************/
	/* OTHER INITIALIZATIONS */
	/*************************/
	// Turn on the sensors light.
	lineSensor.EmittersOn();
	OrangutanTime::delayMilliseconds(500);
	lineSensor.Calibrate();
	OrangutanTime::delayMilliseconds(500);
	
	/**************/
	/* MAIN LOGIC */
	/**************/
	while (1)
	{
		unsigned int linePosition;
		unsigned char speed[] = { 0, 0 };
		int speedCorrection = 0;

		lineSensor.ReadLine(&linePosition, false);
		
		speedCorrection = control.ProportionalIntegral(linePosition);
		
		motorControl.SetSpeed(speed);
	}
}

