#include "RaiseClimber.h"

RaiseClimber::RaiseClimber()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::pullup.get());
}

// Called just before this Command runs the first time
void RaiseClimber::Initialize()
{
	Robot::pullup->Raise();
}

// Called repeatedly when this Command is scheduled to run
void RaiseClimber::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RaiseClimber::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void RaiseClimber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RaiseClimber::Interrupted()
{

}
