#include "PhoenixControlBoard.h"

/// Constructor for Phoenix Control Board
//TODO: Replace number with const.
PhoenixControlBoard::PhoenixControlBoard()
	:
	m_DriveController(new Joystick(1)),
	m_OperatorController(new Joystick(2))
{
}


//TODO: Replace axes # with consts from class.
float PhoenixControlBoard::GetDriveThrottle()
{
	return GetDriveAxis(1);
}

float PhoenixControlBoard::GetDriveTurn(){
	return GetDriveAxis(2);
}

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
