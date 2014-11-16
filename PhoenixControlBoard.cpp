#include "PhoenixControlBoard.h"

/// Constructor for Phoenix Control Board
//TODO: Replace number with const.
PhoenixControlBoard::PhoenixControlBoard()
	:
	m_DriveController(new Joystick(1)),
	m_OperatorController(new Joystick(2))
{
}

/*
/// Returns state of autonomous select button
bool PhoenixControlBoard::GetAutoSelectButton()
{
	if(GetDriveButton(AUTON_BUTTON) && !m_PreviousAuto)
	{
		m_PreviousAuto = GetDriveButton(AUTON_BUTTON);
		return true;
	}
	m_PreviousAuto = GetDriveButton(AUTON_BUTTON);
	return false;
}


/// Returns the state of the quick turn
bool PhoenixControlBoard::GetQuickTurn()
{
	return !GetDriveButton(8);
}
*/

//TODO: Replace axes # with consts from class.
float PhoenixControlBoard::GetDriveThrottle()
{
	return GetDriveAxis(1);
}

float PhoenixControlBoard::GetDriveTurn(){
	return GetDriveAxis(2);
}

/*
float PhoenixControlBoard::GetDriveStickY()
{
	return m_DriveStick->GetRawAxis(LEFT_GAMEPAD_Y);
}

float PhoenixControlBoard::GetSteeringX()
{
	return m_DriveWheel->GetRawAxis(STEERING_X);
}
*/


//----Get Buttons----
bool PhoenixControlBoard::GetDriveButton(const int button)
{
	return m_DriveController->GetRawButton(button);
}

bool PhoenixControlBoard::GetOperatorButton(const int button)
{
	return m_OperatorController->GetRawButton(button);
}

//----Get Joystick Axes----
float PhoenixControlBoard::GetDriveAxis(const int axis)
{
	return m_DriveController->GetRawAxis(axis);
}

float PhoenixControlBoard::GetOperatorAxis(const int axis)
{
	return m_OperatorController->GetRawAxis(axis);
}




/*
bool PhoenixControlBoard::GetDriveButton(const int button)
{
	return m_DriveStick->GetRawButton(button);
}
*/

/*
bool PhoenixControlBoard::GetOperatorButton(const int button)
{
	return m_OperatorPanel->GetRawButton(button);
}
*/

/*
bool PhoenixControlBoard::GetSteeringButton(const int button)
{
	return m_DriveWheel->GetRawButton(button);
}
*/
