#include "PDPReadTotalCurrent.h"

PDPReadTotalCurrent::PDPReadTotalCurrent()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::kPDP.get());
}

// Called just before this Command runs the first time
void PDPReadTotalCurrent::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PDPReadTotalCurrent::Execute()
{
	SmartDashboard::PutNumber("Total Current", Robot::kPDP->pdp->GetTotalCurrent());
}

// Make this return true when this Command no longer needs to run execute()
bool PDPReadTotalCurrent::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PDPReadTotalCurrent::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PDPReadTotalCurrent::Interrupted()
{

}
