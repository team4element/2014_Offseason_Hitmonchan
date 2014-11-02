#ifndef __OPERATOR_CONTROLLER_H__
#define __OPERATOR_CONTROLLER_H__

#include <math.h>
#include <WPILib.h>
#include "../PhoenixRobot.h"
#include "../PhoenixControlBoard.h"
#include "../PhoenixLib/PhoenixLib.h"
#include "../Declarations.h"
#include "../PhoenixConstants.h"

class OperatorController : public GenericController
{	
private:
	OperatorController();
	PhoenixControlBoard* m_CB;
	bool m_PreviousFire;
	bool m_PreviousFullBack;
	bool m_PreviousHalfBack;
public:
	OperatorController(PhoenixControlBoard* controlboard);
	void handle(PhoenixRobot* bot);
};

#endif
