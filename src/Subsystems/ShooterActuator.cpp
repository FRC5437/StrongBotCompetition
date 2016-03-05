#include "ShooterActuator.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

ShooterActuator::ShooterActuator() :
		PIDSubsystem("ShooterActuator", 0.03, 0.0006, 0.0)
{
	Actuator = RobotMap::shooterCANTalon3;
	Actuator->SetFeedbackDevice(CANTalon::AnalogPot);
	SetInputRange(0, 1023);
	SetOutputRange(-1.0, 1.0);
	SetPercentTolerance(1.0);
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double ShooterActuator::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return Actuator->GetPosition();
}

void ShooterActuator::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Actuator->Set(output);
}

void ShooterActuator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void ShooterActuator::Aim(int setpoint) {
	SetSetpoint(setpoint);
	Enable();
}


