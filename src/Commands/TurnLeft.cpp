#include "TurnLeft.h"
#include "../Subsystems/Chassis.h"

TurnLeft::TurnLeft()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
	SetTimeout(1);
}

// Called just before this Command runs the first time
void TurnLeft::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TurnLeft::Execute()
{
	Robot::chassis->Drive(-0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnLeft::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void TurnLeft::End()
{
	Robot::chassis->Drive(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLeft::Interrupted()
{

}
