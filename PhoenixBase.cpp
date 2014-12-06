#include "PhoenixBase.h"

PhoenixBase::PhoenixBase(){
	
	//----------Initialize Member Objects----------------
	m_Bot = new PhoenixRobot();
	m_ControlBoard = new PhoenixControlBoard();
	m_OpController = new OperatorController(m_ControlBoard);
	m_Constants = PhoenixConstants::GetInstance();

	SetPeriod(HZ(ROBOT_HZ));
	GetWatchdog().SetEnabled(false);
	printf("Done constructing PhoenixBase!\n");
}

void PhoenixBase::RobotInit(){
	
}

void PhoenixBase::DisabledInit(){

}

void PhoenixBase::AutonomousInit()
{

}
void PhoenixBase::TeleopInit()
{
	m_Bot->SetController(m_OpController);
	//m_Bot->Reset();
}

void PhoenixBase::DisabledContinuous()
{
	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::AutonomousContinuous()
{
	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::TeleopContinuous()
{
	taskDelay(WAIT_FOREVER);
}

void PhoenixBase::DisabledPeriodic()
{

}
void PhoenixBase::AutonomousPeriodic()
{

}
void PhoenixBase::TeleopPeriodic()
{

	m_Bot->PrintToDS();
	m_Bot->handle();
}

START_ROBOT_CLASS(PhoenixBase);
