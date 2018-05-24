/*
 * PidControl.h
 *
 * Created: 23/05/2018 20:13:27
 *  Author: Javier Rodriguez Posada
 */ 


#ifndef PIDCONTROL_H_
#define PIDCONTROL_H_

namespace Control
{
	class PidControl
	{
		public:
			PidControl(unsigned int consigna);
			
			int Proportional(unsigned int currentValue);
			
			int ProportionalIntegral(unsigned int currentValue);
			
			void SetConsigna(unsigned int consigna);
		private:
			unsigned int _consigna;
			unsigned int _lastError;
	};
}

#endif /* PIDCONTROL_H_ */