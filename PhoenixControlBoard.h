#ifndef __Phoenix_CONTROL_BOARD_H__
#define __Phoenix_CONTROL_BOARD_H__

#include <WPILib.h>

#define SHIFTER_BUTTON			4
#define AUTON_BUTTON			1
#define PID_BUTTON				3

#define LEFT_GAMEPAD_X			1
#define LEFT_GAMEPAD_Y			2
#define RIGHT_GAMEPAD_X			3
#define RIGHT_GAMEPAD_Y			4
#define STEERING_X				1

#define FAST_TURN				6 

/// This class offers access to the 2010 specific Phoenix Control Board
///
class PhoenixControlBoard
{
private:	
	Joystick* m_DriveController;
	Joystick* m_OperatorController;
	//Joystick* m_DriveWheel;
	//Joystick* m_OperatorPanel;
	
	//bool m_PreviousAuto;
public:
	//----Constructor----
	PhoenixControlBoard();
	
	float GetDriveThrottle();
	float GetDriveTurn();
	
	
	//----Hardware Getters----
	bool GetDriveButton(int button);
	bool GetOperatorButton(int button);
	float GetDriveAxis(int axis);
	float GetOperatorAxis(int axis);
};

#endif
