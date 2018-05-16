/*
 * QTRA_Sensor.h
 *
 * Created: 01/05/2018 13:11:21
 *  Author: Javier Rodriguez Posada
 */ 

#ifndef QTRA_SENSOR_H_
#define QTRA_SENSOR_H_

namespace Senses
{
		#define ADC0_PIN 0
		#define ADC1_PIN 1
		#define ADC2_PIN 2
		#define ADC3_PIN 3
		#define ADC4_PIN 4
		#define ADC5_PIN 5
		#define ADC6_PIN 6
		#define ADC7_PIN 7

		#define QTRA_MAX_SENSORS 8

		class QTRASensor
		{
			public:
			// Constructor.
			// sensorPins: pointer to an array. Ex.: {ADC0_PIN, ADC1_PIN, ADC2_PIN}
			// numSensor: number of sensors. It MUST match the number of elements in the array sensorPins. Should not be greater than QTRA_MAX_SENSORS.
			QTRASensor(unsigned char* sensorPins, unsigned char numSensors, unsigned char numSamplesPerSensor);
			
			// Read the sensors value into an array.
			void ReadRaw(unsigned int* sensorValues);
			
			// Read the sensors value into an array. Map each read to range [0-999]. It requires the sensros to be calibrated first to work properly.
			void Read(unsigned int* sensorValues);

			// Read the sensors value and returns a value representing
			// relative position of the sensor from the line: to the left,
			// centered or to the right.
			unsigned int ReadLine(unsigned int* sensorValues, bool whiteLine);
			
			// Turn off the emitters pin.
			void EmittersOff();
			
			// Turns on the emitters pin.
			void EmittersOn();
			
			// Reads the sensors for calibration. The maximum an minimum
			// values are saved and used for read method.
			void Calibrate();
			
			// Reset all calibration done.
			void ResetCalibration();
			
			// Calibrated minimum and maximum values.
			unsigned int *calibratedMinimumOn;
			unsigned int *calibratedMaximumOn;
			unsigned int *calibratedMinimumOff;
			unsigned int *calibratedMaximumOff;
			
			private:
			// Number of sensors in the array.
			unsigned char numSensors;
			
			unsigned char numSamplesPerSensor;
			
			unsigned char sensorPins[QTRA_MAX_SENSORS];
			
			unsigned char portMask;

			unsigned short* calibrationMessures[2];
		};
}

#endif /* QTRA_SENSOR_H_ */