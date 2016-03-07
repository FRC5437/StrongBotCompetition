#include "ShooterAngleAutonomous.h"

ShooterAngleAutonomous::ShooterAngleAutonomous(double setpoint)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterActuator.get());
	SetTimeout(2.0);
	potSetting = setpoint;
}

// Called just before this Command runs the first time
void ShooterAngleAutonomous::Initialize()
{
	Robot::shooterActuator->Aim(potSetting);
}

// Called repeatedly when this Command is scheduled to run
void ShooterAngleAutonomous::Execute()
{
	double position = Robot::shooterActuator->Actuator->GetPosition();
	Robot::logger->log("ShooterAngleAutonomous Execute Actuator Position: " + std::to_string(position));
	SmartDashboard::PutNumber("Shooter Position", position);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterAngleAutonomous::IsFinished()
{

	return abs(Robot::shooterActuator->Actuator->GetClosedLoopError()) <= 5.0 || IsTimedOut();
}

// Called once after isFinished returns true
void ShooterAngleAutonomous::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterAngleAutonomous::Interrupted()
{

}
