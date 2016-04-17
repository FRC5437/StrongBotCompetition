#include "PDP.h"
#include "../RobotMap.h"
#include "../Commands/PDPReadTotalCurrent.h"

PDP::PDP() :
		Subsystem("PDP")
{
	pdp.reset(new PowerDistributionPanel(1));
}

void PDP::InitDefaultCommand()
{
	SetDefaultCommand(new PDPReadTotalCurrent());
}
