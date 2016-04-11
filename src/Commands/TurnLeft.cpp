#include "TurnLeft.h"
#include "../Subsystems/Chassis.h"

TurnLeft::TurnLeft(double time)
{
	Requires(Robot::chassis.get());
	SetTimeout(time);
}

void TurnLeft::Initialize()
{

}

void TurnLeft::Execute()
{
	Robot::chassis->Drive(-0.57, 0.57);
}

bool TurnLeft::IsFinished()
{
	return IsTimedOut();
}

void TurnLeft::End()
{
	Robot::chassis->Drive(0.0,0.0);
}

void TurnLeft::Interrupted()
{

}
