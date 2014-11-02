#ifndef __GENERIC_CONTROLLER_H__
#define __GENERIC_CONTROLLER_H__

#include <WPILib.h>

class PhoenixRobot;

class GenericController
{	
public:
	virtual ~GenericController() {};
	virtual void handle(PhoenixRobot* bot) = 0;
};

#endif
