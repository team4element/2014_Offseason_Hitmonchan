#ifndef __Phoenix_ROBOT_H__
#define __Phoenix_ROBOT_H__


#include <WPILib.h>
#include "Controllers/GenericController.h"
//#include "Subsystems/Intake.h"
//#include "Subsystems/Winch.h"
#include "PhoenixLib/PhoenixLib.h"
#include "PhoenixControlBoard.h"
#include "CounterBase.h"
#include "PhoenixConstants.h"

class PhoenixRobot
{
public:

private:
	int m_DSUpdateCount;
	
	GenericController* m_Controller;
	

	//Motors
	Talon* m_RightDriveA_;
	Talon* m_RightDriveB_;
	Talon* m_RightDriveC_;
	
	Talon* m_LeftDriveA_;
	Talon* m_LeftDriveB_;
	Talon* m_LeftDriveC_;
		
	//Pneumatics
	//Relay* m_Compressor; //TODO: find compressor port.
	
	//Sensors
	//PhoenixLib::PhoenixGyro* m_Gyro;
	
	
	void SetLeftMotors(float val);
	void SetRightMotors(float val);

public:
	PhoenixRobot();
	void Reset();

	void SetController(GenericController* controller);
	void PrintToDS();

	void handle();
	
	//void drive1538Code(float speed, float turn, bool quickTurn);
	
	
	//void driveRobot(double throttle, double turn);
	void setRightPower(double speed);
	void setLeftPower(double speed);
	
	
	//void DriveSpeedTurn(float speed, float turn, bool quickTurn);
	//void DriveLeftRight(float leftDriveValue, float rightDriveValue);
	//void QuickTurn(float turn);
	
	
};

#endif
