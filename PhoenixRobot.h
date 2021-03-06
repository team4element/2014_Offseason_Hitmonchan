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
//	typedef enum
//	{
//		IDLE,
//		ADJUSTING_BALL,
//		DROPPING_INTAKES,
//		WAITING_FOR_RELOAD,
//		AUTO_SETTLING,
//	} e_FiringState;
//
//	typedef enum
//	{
//		SETTLE_EXHAUST_REAR,
//		SETTLE_EXHAUST_REAR_PULSE,
//		SETTLE_EXHAUST_FRONT,
//		SETTLE_EXHAUST_BOTH,
//		SETTLE_PULL_DOWN,
//		SETTLE_IDLE,
//		SETTLE_FINISHED,
//	} e_SettlingState;
private:
	int m_DSUpdateCount;
	
	GenericController* m_Controller;
	
	// Drive Motors
	//Talon* m_RightDrive;
	//Talon* m_LeftDrive;
	
	Talon* m_RightDriveA_;
	Talon* m_RightDriveB_;
	Talon* m_RightDriveC_;
	
	Talon* m_LeftDriveA_;
	Talon* m_LeftDriveB_;
	Talon* m_LeftDriveC_;
	
	//Relay* m_Compressor;
	//DigitalInput* m_PressureSwitch;
	
//	Intake* m_FrontIntake;
	
//	Intake* m_RearIntake;
//	Winch* m_Winch;
	
//	//PhoenixLib::PhoenixGyro* m_Gyro;
//	//Encoder* m_DriveEncoder;
//	//AnalogChannel* m_FrontIR; //  // TODO: front and rear are named backwards, fix
//	//AnalogChannel* m_RearIR;
//	
//	//KinectStick* m_KinectLeftArm;
//	//KinectStick* m_KinectRightArm;
	
//	float m_LeftDriveValue;
//	float m_RightDriveValue;
	
//	double m_FrontIntakeSpeed;
//	bool m_FrontIntakeState;
//	double m_RearIntakeSpeed;
//	bool m_RearIntakeState;
//	
//	double m_BallAdjustTime;
//	e_FiringState m_FiringState;
//	e_SettlingState m_SettlingState;
//	double m_BallSettledTime;
//	
//	double m_PreviousGyroError;
//	double m_PreviousDriveError;
//		
	void SetLeftMotors(float val);
	void SetRightMotors(float val);
public:
	PhoenixRobot();
	void Reset();
	void GyroHandleCalibration();
	//void GyroFinalizeCalibration();
	void SetController(GenericController* controller);
	void PrintToDS();
	//double GetDriveDistance();
	//bool DriveDistanceWithHeading(double heading, double distance);
	//bool DriveWithHeading(double heading, double speed);
//	void SetFrontIntakeState(bool state);
//	void SetRearIntakeState(bool State);
//	void FrontIntake(double speed, bool state);
//	void RearIntake(double speed, bool state);
	//void SetWinchState(Winch::e_WinchState state);
	//void AskForFire();
	//void ForceFire();
	//bool ReadyToFire();
	//bool Reloading();
	//bool ChangeWinchSetpoint(double setpoint);
	//void WinchHoldVoltage(double setpoint);
	//void WinchDespring();
	void driveRobot(double throttle, double turn);
	void setRightPower(double speed);
	void setLeftPower(double speed);
	
	void DriveSpeedTurn(float speed, float turn, bool quickTurn);
	void DriveLeftRight(float leftDriveValue, float rightDriveValue);
	void QuickTurn(float turn);
//	double KinectLeftRight();
//	double GetFrontIR();
//	double GetRearIR();
//	void AutoSettle();
//	e_SettlingState GetSettledState();
	
	void handle();
};

#endif
