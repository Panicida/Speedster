/*
 * SerialData.h
 *
 * Created: 02/06/2018 23:11:14
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef SERIALDATA_H_
#define SERIALDATA_H_

namespace Communication
{
	class SerialData
	{
		public:
			SerialData(const char* string);
			SerialData(int number);
			void FreeMemory();
			unsigned char* Data;
		
		private:
			void AddString(const char* string);
			void AddNumber(int number);
	};
}



#endif /* SERIALDATA_H_ */