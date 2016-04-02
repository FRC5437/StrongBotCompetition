#include "PDP.h"
#include "../RobotMap.h"
#include "../Commands/PDPReadTotalCurrent.h"

PDP::PDP() :
		Subsystem("PDP")
{
	pdp.reset(new PowerDistributionPanel());
}

void PDP::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new PDPReadTotalCurrent());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
