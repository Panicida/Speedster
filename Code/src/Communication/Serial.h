/*
 * Serial.h
 *
 * Created: 31/05/2018 19:37:12
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

namespace Communication
{
	class Serial
	{
		public:
			Serial(unsigned int baudrate);
			void Send(unsigned char string);
	};
}

#endif /* SERIAL_H_ */