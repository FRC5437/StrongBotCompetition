#include "WaitDuration.h"

WaitDuration::WaitDuration(double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void WaitDuration::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitDuration::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitDuration::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void WaitDuration::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitDuration::Interrupted()
{

}
