/*
 * QTRA_Sensor.h
 *
 * Created: 28/04/2018 15:57:16
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef QTRA_SENSOR_H_
#define QTRA_SENSOR_H_

class QTRA_Sensor
{
	public:
		QTRA_Sensor();
		bool Read(int& values);
	private:
		bool[] pins;
		bool SetPins();
};

#endif /* QTRA_SENSOR_H_ */