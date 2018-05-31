/*
 * motor.h
 *
 * Created: 10/05/2018 19:25:09
 *  Author: Javier Rodriguez Posada
 */ 

#ifndef MOTOR_H_
#define MOTOR_H_

namespace Motion
{
	enum MotorPosition
	{
		Left,
		Right
	};

	enum MotorControlMode
	{
		// One PWM pin (speed) and one simple digital output pin (direction).
		Simple,
		
		// Two PWM variable pins. Only one pin is used a PWM signal at a time.
		// Direction is determined by which pin has each role.
		Complex
	};
	
	enum PWMPin
	{
		TC0,
		TC1,
		TC2
	};

	struct MotorInfoStruct
	{
		MotorPosition motorPosition;
		
		// Speed pin. In complex mode this will be the pin used for PWM of the forward movement.
		PWMPin pwmPin;
	};
	
	struct MotorSpeedStruct
	{
		unsigned char speed;
		PWMPin pwmPin;
	};

	class Motors
	{
		public :
			Motors(MotorPosition* motorPosition, unsigned char numMotors);

			// Sets the motors' speed.
			// speed: array with the desired speed for each motor. Order has to match constructor.
			void SetSpeed(int* speed);
			
			// Fill a given MotorInfo struct.
			static void SetMotorInfo(MotorInfoStruct* motorInfo, MotorPosition motorPosition, PWMPin pwmPin);
		
		private:
			// Internal function to set the motors' speed.
			// speed: array with the desired speed for each motor. Order has to match constructor.
			bool CapSpeed(int* speed);

			// Initializes the corresponding timers.
			void InitializeTC0();
			void InitializeTC1();
			void InitializeTC2();
			
			// Set speed into the corresponding pin.
			virtual void SetTC0Speed(unsigned char speed, bool forward) = 0;
			virtual void SetTC1Speed(unsigned char speed, bool forward) = 0;
			virtual void SetTC2Speed(unsigned char speed, bool forward) = 0;
			
		protected:
			// Number of motors.
			unsigned char _numMotors;
			
			MotorInfoStruct* _motorInfo;
	};
	
	class MotorsComplex : public Motors
	{
		public:
			// Constructor.
			// motorsInfo has to be an array of size numMotors.
			MotorsComplex(MotorPosition* motorInfo, unsigned char numMotors);
		private:
			// Set speed into the corresponding pin.
			void SetTC0Speed(unsigned char speed, bool forward);
			void SetTC1Speed(unsigned char speed, bool forward);
			void SetTC2Speed(unsigned char speed, bool forward);
	};
}

#endif /* MOTOR_H_ */
