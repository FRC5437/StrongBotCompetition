#include "ShooterHasBall.h"

ShooterHasBall::ShooterHasBall()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
}

// Called just before this Command runs the first time
void ShooterHasBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShooterHasBall::Execute()
{
	SmartDashboard::PutBoolean("Has Ball", Robot::shooter->HasBall());
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterHasBall::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterHasBall::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterHasBall::Interrupted()
{

}
