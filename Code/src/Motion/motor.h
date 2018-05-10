/*
 * motor.h
 *
 * Created: 10/05/2018 19:25:09
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

enum MotorPosition : unsigned char
{
	left,
	right	
};

struct MotorInfo
{
	MotorPosition motorPosition;
	unsigned char speedPin;
	unsigned char directionPin;
}; 

class Motors
{
	public:
		// Constructor.
		// motorsInfo has to be an array of size numMotors.
		Motors(MotorInfo* motorsInfo, unsigned char numMotors);
		
		// Sets the motors' speed.
		// speed: array with the desired speed for each motor. Order has to match constructor.
		void SetSpeed(short* speed);
		
		// Sets the motors' direction.
		// direction: (true = forward, false = reversed) array with the desired direction for each motor. Order has to match constructor.
		void SetDirection(bool* direction);
	private:
		// Configure the PWM registries.
		void InitializePWM();
		
		// Number of motors.
		unsigned char numMotors;
		
};

#endif /* MOTOR_H_ */