#ifndef _INTAKE_H_
#define _INTAKE_H_

class Intake
{
public:

	
	
private:
	Talon* m_MotorA;
	Solenoid* m_OpenPiston;
	//Once we add a limit switch, add this in there.
	
public:
	Intake();
	void handle();
	
	
	
	
};




#endif
