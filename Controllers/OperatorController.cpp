#include "OperatorController.h"

OperatorController::OperatorController(PhoenixControlBoard* controlboard)
	:
	m_CB(controlboard)
{
}

void OperatorController::handle(PhoenixRobot* bot)
{
	if(m_CB->GetDriveButton(JOY_BUTTON_B)) //B-button
	{
		//bot->driveRobot(m_CB->GetDriveThrottle(),m_CB->GetDriveTurn());
		//bot->drive1538Code(m_CB->GetDriveAxis(JOY_AXIS_LJ_Y),m_CB->GetDriveAxis(JOY_AXIS_RJ_X),m_CB->GetDriveButton(JOY_BUTTON_RB)); //(drive throttle, drive turning)
		//TODO: Figure out which mapping scheme we want.
	}
	
	//printf("Controlling...\n");

}
