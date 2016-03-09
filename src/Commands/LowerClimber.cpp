#include "LowerClimber.h"

LowerClimber::LowerClimber()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::pullup.get());
}

// Called just before this Command runs the first time
void LowerClimber::Initialize()
{
	Robot::pullup->Drop();
}

// Called repeatedly when this Command is scheduled to run
void LowerClimber::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowerClimber::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowerClimber::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerClimber::Interrupted()
{

}
