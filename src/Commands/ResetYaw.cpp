#include "ResetYaw.h"

ResetYaw::ResetYaw(): Command()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::navX.get());
	SetTimeout(1);
}

// Called just before this Command runs the first time
void ResetYaw::Initialize()
{
	Robot::navX->ahrs->ZeroYaw();
}

// Called repeatedly when this Command is scheduled to run
void ResetYaw::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetYaw::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void ResetYaw::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetYaw::Interrupted()
{

}
