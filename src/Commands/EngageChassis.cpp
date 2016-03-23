#include "EngageChassis.h"

EngageChassis::EngageChassis()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void EngageChassis::Initialize()
{
	Robot::chassis->Engage();
}

// Called repeatedly when this Command is scheduled to run
void EngageChassis::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EngageChassis::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void EngageChassis::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageChassis::Interrupted()
{

}
