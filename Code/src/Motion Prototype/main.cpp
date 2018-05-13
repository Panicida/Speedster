/*
 * Motion Prototype.cpp
 *
 * Created: 10/05/2018 20:29:00
 * Author : Javier Rodriguez Posada
 */ 

#include <avr/io.h>
#include "Motion/motor.h"

void Read(unsigned int* sensorValue)
{
	// Store current state of various registers.
	unsigned char admux = ADMUX;
	unsigned char adcsra = ADCSRA;
	unsigned char ddr = DDRD;
	unsigned char port = PORTD;
	
	// Wait for any current conversion to finish.
	while (ADCSRA & (1 << ADSC));
	
	// Reset values.
	sensorValue = 0;
	
	// Set all sensors pins to high-Z inputs
	DDRC &= ~(1 << 1);
	PORTC &= ~(1 << 1);
	
	// Set analog input channel
	ADMUX = (1 << REFS0) | 1;
	
	// Start the conversion.
	ADCSRA |= (1 << ADSC);
	
	// Wait for conversion to finish.
	while (ADCSRA & (1 << ADSC));
	
	// Add in the conversion result.
	*sensorValue = ADC;
	
	// Restore registry default values.
	ADMUX = admux;
	ADCSRA = adcsra;
	PORTD = port;
	DDRD = ddr;
}

int main(void)
{
	// Configure analog input on pin ADC7 (trimmer potentiometer)
	// The value will be used to control the speed.
	// Configure ADC settings. Prescalar set to 156kHz
	ADCSRA |= (1 << ADEN)| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	
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
	
    /* Replace with your application code */
	
	unsigned int speed = 0;
	
    while (1) 
    {
		// For some reason this line break the program.
		//Read(&speed);
		Motion::MotorSpeedStruct motorSpeed;
		motorSpeed.speed = 100;
		motorSpeed.pwmPin = Motion::TC0;
		motors.SetSpeed(&motorSpeed);
    }
}

