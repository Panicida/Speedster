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
			static 
		private:
			
	};
}

#endif /* PIDCONTROL_H_ */

/*
void loop ()
{
	unsigned int valorSensores [4];
	
	unsigned int posicion = sensoresReflexion.readLine(valorSensores);
	
	seguirLinea (posicion);
}

void seguirLinea (int posicion)
{
	int error = posicion - 1500;
	
	int velocidadDiferencial = error / 4 + 6 * (error - ultimoError);
	ultimoError = error;
	
	int motorI = MAX_SPEED + velocidadDiferencial;
	int motorD = MAX_SPEED - velocidadDiferencial;
	
	if (motorI > MAX_SPEED)
	{
		motorI = MAX_SPEED;
	}
	if (motorD > MAX_SPEED)
	{
		motorD = MAX_SPEED;
	}
	if (motorI < -MAX_SPEED)
	{
		motorI = -MAX_SPEED;
	}
	if (motorD < -MAX_SPEED)
	{
		motorD = -MAX_SPEED;
	}
	
	velocidad(motorI,motorD);
}

*/