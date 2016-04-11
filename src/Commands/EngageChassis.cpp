#include "EngageChassis.h"

EngageChassis::EngageChassis()
{
	Requires(Robot::chassis.get());
}

void EngageChassis::Initialize()
{
	Robot::chassis->Engage();
}

void EngageChassis::Execute()
{

}

bool EngageChassis::IsFinished()
{
	return true;
}

void EngageChassis::End()
{

}

void EngageChassis::Interrupted()
{

}
