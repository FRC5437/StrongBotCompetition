#include "TurnRight.h"
#include "../Subsystems/Chassis.h"

TurnRight::TurnRight(double time)
{
	Requires(Robot::chassis.get());
	SetTimeout(time);
}

void TurnRight::Initialize()
{

}

void TurnRight::Execute()
{
	Robot::chassis->Drive(0.57, -0.57);
}

bool TurnRight::IsFinished()
{
	return IsTimedOut();
}

void TurnRight::End()
{
	Robot::chassis->Drive(0.0,0.0);
}

void TurnRight::Interrupted()
{

}
