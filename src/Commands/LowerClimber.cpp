#include "LowerClimber.h"

LowerClimber::LowerClimber()
{
	Requires(Robot::pullup.get());
}

void LowerClimber::Initialize()
{
	Robot::pullup->Drop();
}

void LowerClimber::Execute()
{

}

bool LowerClimber::IsFinished()
{
	return true;
}

void LowerClimber::End()
{

}

void LowerClimber::Interrupted()
{

}
