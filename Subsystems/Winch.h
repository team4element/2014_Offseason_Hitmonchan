#ifndef _WINCH_H_
#define _WINCH_H_

class Winch
{
public:

	
	
private:
	Talon* m_MotorA;
	Talon* m_MotorB;
	AnalogChannel* m_Pot;
	
public:
	Winch();
	void handle();
	
	
	
	
};




#endif
