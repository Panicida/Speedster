/*
 * Serial.h
 *
 * Created: 31/05/2018 19:37:12
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#include "SerialData.h"

namespace Communication
{
	class Serial
	{
		public:
			Serial(unsigned int baudrate);
			static void Send(unsigned char* data);
		private:
			static bool IsBufferEmpty();
		public:
			static void EnableTxInterrupt();
			static void DisableTxInterrupt();
			static void SendWithInterrupts();
			static unsigned int _dataSize;
			static unsigned char* _sendBuffer;
			static unsigned int _bytePosition;
	};
}

#endif /* SERIAL_H_ */