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
			Motors(MotorInfoStruct* motorInfo, unsigned char numMotors);
			
			// Sets the motors' speed.
			// speed: array with the desired speed for each motor. Order has to match constructor.
			void SetSpeed(unsigned char* speed);
			
			// Sets the motors' direction.
			// direction: (true = forward, false = reversed) array with the desired direction for each motor. Order has to match constructor.
			virtual void SetDirection(bool direction) = 0;
			
			// Fill a given MotorInfo struct.
			static void SetMotorInfo(MotorInfoStruct* motorInfo, MotorPosition motorPosition, PWMPin pwmPin);
		
		private:
			// Initializes the corresponding timers.
			void InitializeTC0();
			void InitializeTC1();
			void InitializeTC2();
			
			// Set speed into the corresponding pin.
			virtual void SetTC0Speed(unsigned char speed) = 0;
			virtual void SetTC1Speed(unsigned char speed) = 0;
			virtual void SetTC2Speed(unsigned char speed) = 0;
			
		protected:
			// Number of motors.
			unsigned char _numMotors;
			
			MotorInfoStruct* _motorInfo;
			
			// Whether the motor should run forward or not.
			bool _forward;
	};
	
	class MotorsComplex : public Motors
	{
		public:
			// Constructor.
			// motorsInfo has to be an array of size numMotors.
			MotorsComplex(MotorInfoStruct* motorInfo, unsigned char numMotors);
			
			// Sets the motors' direction.
			// direction: (true = forward, false = reversed) array with the desired direction for each motor. Order has to match constructor.
			void SetDirection(bool direction);
		private:
			// Set speed into the corresponding pin.
			void SetTC0Speed(unsigned char speed);
			void SetTC1Speed(unsigned char speed);
			void SetTC2Speed(unsigned char speed);
	};
}

#endif /* MOTOR_H_ */
