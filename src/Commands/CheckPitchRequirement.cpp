#include "CheckPitchRequirement.h"

CheckPitchRequirement::CheckPitchRequirement()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::navX.get());
}

// Called just before this Command runs the first time
void CheckPitchRequirement::Initialize()
{
if (Robot::navX->ahrs->GetRoll() >	 -8.0) {
	Robot::logger->log("Roll check failed, remove all commands from scheduler");
	Scheduler::GetInstance()->RemoveAll();
}
}

// Called repeatedly when this Command is scheduled to run
void CheckPitchRequirement::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CheckPitchRequirement::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CheckPitchRequirement::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CheckPitchRequirement::Interrupted()
{

}
