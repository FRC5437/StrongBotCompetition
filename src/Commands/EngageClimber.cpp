#include "EngageClimber.h"

EngageClimber::EngageClimber()
{
	Requires(Robot::chassis.get());
}

void EngageClimber::Initialize()
{
	Robot::chassis->Disengage();
}

void EngageClimber::Execute()
{

}

bool EngageClimber::IsFinished()
{
	return false;
}

void EngageClimber::End()
{

}

void EngageClimber::Interrupted()
{

}
