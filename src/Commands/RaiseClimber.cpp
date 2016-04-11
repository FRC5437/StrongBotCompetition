#include "RaiseClimber.h"

RaiseClimber::RaiseClimber()
{
	Requires(Robot::pullup.get());
}

void RaiseClimber::Initialize()
{
	Robot::pullup->Raise();
}

void RaiseClimber::Execute()
{

}

bool RaiseClimber::IsFinished()
{
	return true;
}

void RaiseClimber::End()
{

}

void RaiseClimber::Interrupted()
{

}
