#include "ShooterAngleAutonomous.h"

ShooterAngleAutonomous::ShooterAngleAutonomous(double setpoint)
{

	Requires(Robot::shooterActuator.get());
	SetTimeout(2.0);
	potSetting = setpoint;
}

void ShooterAngleAutonomous::Initialize()
{
	Robot::shooterActuator->Aim(potSetting);
}

void ShooterAngleAutonomous::Execute()
{
	double position = Robot::shooterActuator->Actuator->GetPosition();
	SmartDashboard::PutNumber("Shooter Position", position);
}

bool ShooterAngleAutonomous::IsFinished()
{

	return abs(Robot::shooterActuator->Actuator->GetClosedLoopError()) <= 5.0 || IsTimedOut();
}

void ShooterAngleAutonomous::End()
{
	Robot::logger->log("ShooterAngleAutonomous Execute Actuator Position: " + std::to_string(Robot::shooterActuator->Actuator->GetPosition()));

}

void ShooterAngleAutonomous::Interrupted()
{

}
