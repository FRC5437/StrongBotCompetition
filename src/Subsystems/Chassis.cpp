#include "Chassis.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "../Commands/DriveRobot.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
static double kP = 0.03;
static double kI = 0.004;
static double kD = 0.002;
static double kF = 0.0;

Chassis::Chassis() : PIDSubsystem("Chassis", kP, kI, kD, kF) {
	cANTalon1 = RobotMap::chassisCANTalon1;
	cANTalon2 = RobotMap::chassisCANTalon2;
	robotDrive21 = RobotMap::chassisRobotDrive21;
	SetInputRange(-180.0, 180.0);
	SetOutputRange(-1.0, 1.0);
	SetAbsoluteTolerance(0.8);
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
}

double Chassis::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return Robot::navX->ahrs->GetYaw();
}

void Chassis::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	Drive(output, -output);
}

void Chassis::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveRobot());
}

void Chassis::Drive(double left, double right) {
	robotDrive21->TankDrive(left, right);
}

void Chassis::Drive(std::shared_ptr<Joystick> joy1, std::shared_ptr<Joystick> joy2) {
	Drive(-joy1->GetRawAxis(1), -joy2->GetRawAxis(1));
}
