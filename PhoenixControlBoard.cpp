#include "PhoenixControlBoard.h"

/// Constructor for Phoenix Control Board
PhoenixControlBoard::PhoenixControlBoard()
	:
	m_DriveStick(new Joystick(1)),
	m_DriveWheel(new Joystick(2)),
	m_OperatorPanel(new Joystick(3)),
	m_PreviousAuto(false)
{
}

/// Returns state of shifter switch
float PhoenixControlBoard::GetDriveAxis(unsigned int axis)
{
	return m_DriveStick->GetRawAxis(axis);
}

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

float PhoenixControlBoard::GetDriveStickY()
{
	return m_DriveStick->GetRawAxis(LEFT_GAMEPAD_Y);
}

float PhoenixControlBoard::GetSteeringX()
{
	return m_DriveWheel->GetRawAxis(STEERING_X);
}

bool PhoenixControlBoard::GetDriveButton(const int button)
{
	return m_DriveStick->GetRawButton(button);
}

bool PhoenixControlBoard::GetOperatorButton(const int button)
{
	return m_OperatorPanel->GetRawButton(button);
}

bool PhoenixControlBoard::GetSteeringButton(const int button)
{
	return m_DriveWheel->GetRawButton(button);
}
