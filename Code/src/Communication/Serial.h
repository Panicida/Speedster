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
			Serial(unsigned int baudrate, int maxDataSize);
			static void Send(char* data, int dataSize);
		private:
			void InitializesRegistries(unsigned int baudrate);
			static bool IsBufferEmpty();
		public:
			static void EnableTxInterrupt();
			static void DisableTxInterrupt();
			static void SendWithInterrupts();
			static int _dataSize;
			static char* _sendBuffer;
			static int _bytePosition;
	};
}

#endif /* SERIAL_H_ */