#include "HighGear.h"

HighGear::HighGear()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::transmission.get());
}

// Called just before this Command runs the first time
void HighGear::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HighGear::Execute()
{
	Robot::transmission->HighGear();
}

// Make this return true when this Command no longer needs to run execute()
bool HighGear::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void HighGear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighGear::Interrupted()
{

}
