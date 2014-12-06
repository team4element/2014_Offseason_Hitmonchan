#include "PhoenixRobot.h"
#include "PhoenixBase.h"


//TODO: initializer list
/// Constructor for PhoenixRobot
PhoenixRobot::PhoenixRobot()
{	
	m_DSUpdateCount = 0;
		
	m_Controller = NULL;
	// Set up drive motors
	m_RightDriveA_ = new Talon(PWM_RIGHT_DRIVEA_);
	m_RightDriveB_ = new Talon(PWM_RIGHT_DRIVEB_);
	m_RightDriveC_ = new Talon(PWM_RIGHT_DRIVEC_);
	
	m_LeftDriveA_ = new Talon(PWM_LEFT_DRIVEA_);
	m_LeftDriveB_ = new Talon(PWM_LEFT_DRIVEB_);
	m_LeftDriveC_ = new Talon(PWM_LEFT_DRIVEC_);
}

void PhoenixRobot::Reset()
{

}

void PhoenixRobot::SetController(GenericController* controller)
{
	m_Controller = controller;
}

void PhoenixRobot::PrintToDS()
{
	DriverStationLCD* ds = DriverStationLCD::GetInstance();
	
	ds->Printf(DriverStationLCD::kUser_Line1, 1, "Hi, it works");
	ds->UpdateLCD();
}


void PhoenixRobot::handle()
{	
	if(m_Controller == NULL)
	{
		printf("No controller for PhoenixRobot!!\n");
		return;
	}
	//if there is no controller. (ie: operatorcontrol/autocontrol)
	
	//printf("Handling...\n");
	m_Controller->handle(this);
}

//void PhoenixRobot::drive1538Code(float throttle, float turn, bool quickTurn){
//	
//	float sensitivity = 0; //Turning sensitivity
//	//float unscaled_turn = 0; //Turning before sensitivity changes
//
//	if(throttle < 0.10 && throttle > -0.10)
//		throttle = 0;
//	if(turn < 0.10 && turn > -0.10 || (throttle == 0 && !quickTurn))
//		turn = 0;
//	
//	if(quickTurn)
//		sensitivity = 1;
//	else
//		sensitivity = 0.4;
//	
//	
//	
//	turn *= sensitivity;
//	turn = -turn;
//	float leftPower = PhoenixLib::LimitMix(throttle + turn);  //:: is the scope.
//	float rightPower = PhoenixLib::LimitMix(throttle - turn);	
//		
//	setLeftPower(leftPower);
//	setRightPower(rightPower);
//	
//}

//double PhoenixRobot::skim(float input)
//{
//	double skimGain = .01;
//	if(input > 1.0)
//		return -((v-1.0) * skimGain);
//	else if (input < -1.0)
//		return -((v+1.0) * skimGain);
//	return 0.0;
//}

void PhoenixRobot::setRightPower(double speed)
{

	if (speed < -1.0)
	{
		speed = -1.0;
	}
	else if (speed > 1.0)
	{
		speed = 1.0;
	}
	
	m_RightDriveA_->Set(-speed);
	m_RightDriveB_->Set(speed);
	m_RightDriveC_->Set(speed);
	
}



void PhoenixRobot::setLeftPower(double speed)
{

	if (speed < -1.0)
	{
		speed = -1.0;
	}
	else if (speed > 1.0)
	{
		speed = 1.0;
	}
	
	m_LeftDriveA_->Set(speed);
	m_LeftDriveB_->Set(-speed);
	m_LeftDriveC_->Set(-speed);
	
}
