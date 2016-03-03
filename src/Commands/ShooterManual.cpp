#include "ShooterManual.h"

ShooterManual::ShooterManual()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterManual::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterManual::Execute()
{
	Robot::shooter->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterManual::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterManual::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterManual::Interrupted()
{

}
