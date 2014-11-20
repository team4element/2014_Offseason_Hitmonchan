#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__

#define ROBOT_HZ						400

#define PhoenixCONSTANTS_DEFAULT_FILE		"constants.ini"

// Number of accumulation periods to be summed
#define PhoenixGYRO_RING_SIZE				5
// Length of an accumulation period in seconds
#define PhoenixGYRO_ACCUMULATION_PERIOD		1.0

#define GYRO_SENSITIVITY				0.007

/*
#define EXHAUST_REAR					4
#define EXHAUST_FRONT					1
#define INTAKE_FRONT					3
#define INTAKE_REAR						2
#define FAR								5
*/

// PWM ports
/*#define PWM_LEFT_DRIVE				1
#define PWM_FRONT_INTAKE_A				2
#define PWM_FRONT_INTAKE_B				3
#define PWM_REAR_INTAKE_A				4
#define PWM_REAR_INTAKE_B				5
#define PWM_WINCH_A						6
#define PWM_WINCH_B						7
#define PWM_RIGHT_DRIVE					8
*/
//Motor Definitions
#define PWM_RIGHT_DRIVEA_				10 //I think this is the MiniCIM
#define PWM_RIGHT_DRIVEB_				8 //TODO: Conflict.  Is this 8 or 9?  Ref. google docs for that one.
#define PWM_RIGHT_DRIVEC_				9
#define PWM_LEFT_DRIVEA_				1
#define PWM_LEFT_DRIVEB_				2
#define PWM_LEFT_DRIVEC_				3

#define PWM_INTAKE_MOTOR				6
#define PWM_ARM_MOTOR					4
#define PWM_WINCH_MOTOR					7

//Pneumatics
//#define PRESSURE_SWITCH				1
//#define SPIKE							1

//#define SOLENOID_1_BACK

// Digital outputs
#define RELAY_COMPRESSOR				1

// Digital inputs
#define DIGITAL_PRESSURE_SWITCH			1



//Sensors
#define GYRO_DRIVE						1 //TODO: Find Correct Port
#define POT_ARM							2
#define WINCH_POT						3

//#define DIGITAL_ENCODER_A				2
//#define DIGITAL_ENCODER_B				3


//Xbox Joystick map
//http://www.chiefdelphi.com/forums/showthread.php?t=120879&highlight=xbox+map

#define JOY_AXIS_LJ_Y					1
#define JOY_AXIS_LJ_X					2
#define JOY_AXIS_TRIGGER				3
#define JOY_AXIS_RJ_X					4
#define JOY_AXIS_RJ_Y					5
#define JOY_AXIS_DPAD					6

#define JOY_BUTTON_A					1
#define JOY_BUTTON_B					2
#define JOY_BUTTON_X					3
#define JOY_BUTTON_Y					4
#define JOY_BUTTON_LB					5
#define JOY_BUTTON_RB					6
#define JOY_BUTTON_BACK					7
#define JOY_BUTTON_START				8
#define JOY_BUTTON_LJPRESS				9
#define JOY_BUTTON_RJPress				10


//Operator Controls



//Linearization...



//Drive Constants
//DECLARE_DOUBLE(turnSensLow, 1.1)
//DECLARE_DOUBLE(turnSensHigh, 1.4)
//DECLARE_DOUBLE(inertiaGain, .0035)

// Shooter
//DECLARE_DOUBLE(shooterFenderSpeed, 36.0)
//DECLARE_DOUBLE(shooterFarFenderSpeed, 40)
//DECLARE_DOUBLE(shooterKeyCloseSpeed, 49.5)
//DECLARE_DOUBLE(shooterKeyFarSpeed, 52)
//DECLARE_DOUBLE(shooterSpeedIncrement, 0.5)
//DECLARE_DOUBLE(shooterBridgeSpeed, 56)


// PID constants
//DECLARE_DOUBLE(driveKP, 0.12)
//DECLARE_DOUBLE(driveKI, 0.0)
//DECLARE_DOUBLE(driveKD, 1.2)
//DECLARE_DOUBLE(driveVelKP, 0.0006)
//DECLARE_DOUBLE(driveVelKI, 0.0000)
//DECLARE_DOUBLE(driveVelKD, 0.0005)
//DECLARE_DOUBLE(baseLockKP, 1.5)
//DECLARE_DOUBLE(baseLockKI, 0.01)
//DECLARE_DOUBLE(baseLockKD, 0)
//DECLARE_DOUBLE(shooterKP, 0.0)
//DECLARE_DOUBLE(shooterKI, 0.0)
//DECLARE_DOUBLE(shooterKD, 0.0)
//DECLARE_DOUBLE(turnKP, 0.074)
//DECLARE_DOUBLE(turnKI, 0.000)
//DECLARE_DOUBLE(turnKD, 0.550)
//DECLARE_DOUBLE(breakStaticOffset, 0.4)
//DECLARE_DOUBLE(autoCameraAlignKP, 0.115)
//DECLARE_DOUBLE(autoCameraAlignKI, 0.004)
//DECLARE_DOUBLE(autoCameraAlignKD, 0.05)
//DECLARE_DOUBLE(straightDriveGain, 0.05)
//
//// Automomous
//DECLARE_DOUBLE(autoShootKeyVel, 53.5)
//DECLARE_DOUBLE(autoAlignThreshold, .5)
//
//// Turning
//DECLARE_DOUBLE(turnNonlinHigh, 0.9)
//DECLARE_DOUBLE(turnNonlinLow, 0.8)
//DECLARE_DOUBLE(negInertiaHigh, 5.0) // Was 10.0
//DECLARE_DOUBLE(senseHigh, 1.2)
//DECLARE_DOUBLE(negInertiaLowMore, 2.5)  // Was 5.0
//DECLARE_DOUBLE(negInertiaLowLessExt, 5.0)  // Was 10.0
//DECLARE_DOUBLE(negInertiaLowLess, 3.0)  // Was 6.0
//DECLARE_DOUBLE(senseLow, 1.10)
//DECLARE_DOUBLE(senseCutoff, 0.1)
//DECLARE_DOUBLE(quickStopTimeConstant, .1)
//DECLARE_DOUBLE(quickStopStickScalar, 5)
//DECLARE_DOUBLE(driveControllerKiTurn, 0.15)
//
//// Offsets
//DECLARE_DOUBLE(hardBallOffset, -.2)
//DECLARE_DOUBLE(wtfHardBallOffset, -.5)
//DECLARE_DOUBLE(softBallOffset, .2)
//DECLARE_DOUBLE(wtfSoftBallOffset, .5)

/*
// Solenoid outputs
#define SOLENOID_FRONT_INTAKE_A			6
#define SOLENOID_FRONT_INTAKE_B			3
#define SOLENOID_REAR_INTAKE_A			5
#define SOLENOID_REAR_INTAKE_B			4
#define SOLENOID_WINCH_LOCK				2
#define SOLENOID_WINCH_FIRE				1

// Analog inputs
#define ANALOG_WINCH_POT				1
#define ANALOG_GYRO						2
#define ANALOG_FRONT_IR					3
#define ANALOG_REAR_IR					4

*/
#endif
