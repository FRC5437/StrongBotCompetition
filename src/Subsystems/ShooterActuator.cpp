#include "ShooterActuator.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"

ShooterActuator::ShooterActuator() :
		PIDSubsystem("ShooterActuator", 0.006, 0.0, 0.0)
{
	Actuator = RobotMap::shooterCANTalon3;
	Actuator->SetFeedbackDevice(CANTalon::AnalogPot);
	Actuator->SetAllowableClosedLoopErr(10.0);
	SetInputRange(0.0, 1023.0);
	SetOutputRange(-1.0, 1.0);
	SetAbsoluteTolerance(10.0);
}

double ShooterActuator::ReturnPIDInput()
{
}

void ShooterActuator::UsePIDOutput(double output)
{
}

void ShooterActuator::InitDefaultCommand()
{

}

void ShooterActuator::Aim(double setpoint) {
	Robot::logger->log("ShooterActuator Aim with setpoint = " + std::to_string(setpoint));
	Actuator->Set(setpoint);
	Actuator->Enable();
}


