#include "EngageClimber.h"

EngageClimber::EngageClimber()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void EngageClimber::Initialize()
{
	Robot::chassis->Disengage();
}

// Called repeatedly when this Command is scheduled to run
void EngageClimber::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool EngageClimber::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void EngageClimber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageClimber::Interrupted()
{

}
