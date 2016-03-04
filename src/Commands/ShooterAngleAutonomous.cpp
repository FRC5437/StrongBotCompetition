#include "ShooterAngleAutonomous.h"

ShooterAngleAutonomous::ShooterAngleAutonomous()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterActuator.get());
}

// Called just before this Command runs the first time
void ShooterAngleAutonomous::Initialize()
{
	Robot::shooterActuator->Aim(845);
}

// Called repeatedly when this Command is scheduled to run
void ShooterAngleAutonomous::Execute()
{
	SmartDashboard::PutNumber("Shooter Position", Robot::shooterActuator->Actuator->GetPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterAngleAutonomous::IsFinished()
{
	return Robot::shooterActuator->OnTarget();
}

// Called once after isFinished returns true
void ShooterAngleAutonomous::End()
{
	Robot::shooterActuator->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterAngleAutonomous::Interrupted()
{

}
