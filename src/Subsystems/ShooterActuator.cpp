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
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double ShooterActuator::ReturnPIDInput()
{
	//double position = Actuator->GetPosition();
	//Robot::logger->log("ShooterActuator ReturnPIDInput GetPosition " + std::to_string(position));
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	//return position;
}

void ShooterActuator::UsePIDOutput(double output)
{
	//Robot::logger->log("ShooterActuator UsePIDOutput = " + std::to_string(output));
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//Actuator->Set(output);
}

void ShooterActuator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());

}

void ShooterActuator::Aim(double setpoint) {
	Robot::logger->log("ShooterActuator Aim with setpoint = " + std::to_string(setpoint));
	Actuator->SetSetpoint(setpoint);
	Actuator->Enable();
	//Actuator->Set(setpoint);
}


