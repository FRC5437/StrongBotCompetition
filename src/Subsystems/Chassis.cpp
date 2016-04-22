#include "Chassis.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "../Commands/DriveRobot.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
static double kP = 0.05;
static double kI = 0.0275;
static double kD = 0.08;
static double kF = 0.0;

Chassis::Chassis() : PIDSubsystem("Chassis", kP, kI, kD, kF) {
	cANTalon1 = RobotMap::chassisCANTalon1;
	cANTalon2 = RobotMap::chassisCANTalon2;
	robotDrive21 = RobotMap::chassisRobotDrive21;
	climberShift.reset(new Solenoid(5));
	SetInputRange(-180.0, 180.0);
	SetOutputRange(-0.6, 0.6);
	SetAbsoluteTolerance(0.3);
	GetPIDController()->SetContinuous(true);

}

double Chassis::ReturnPIDInput()
{
	return Robot::navX->ahrs->GetYaw();
}

void Chassis::UsePIDOutput(double output)
{
	if (output > 0.0)
	{
		//if (output < 0.2)
		//{
			//output = (output + 0.1);
		//}
	}
	else
	{
		//if (output > -0.2)
		//{
		    //output = (output-0.1);
		//}
	}


	Drive(output, -output);
}

void Chassis::InitDefaultCommand()
{
	SetDefaultCommand(new DriveRobot());
}

void Chassis::Drive(double left, double right) {
	robotDrive21->TankDrive((left), (right), false);
}

void Chassis::Drive(std::shared_ptr<Joystick> joy1, std::shared_ptr<Joystick> joy2) {
	Drive(-joy1->GetRawAxis(1) * 0.7, -joy2->GetRawAxis(1) * 0.7);
}

void Chassis::DriveHigh(std::shared_ptr<Joystick> joy1, std::shared_ptr<Joystick> joy2) {
	Drive((-joy1->GetRawAxis(1)), (-joy2->GetRawAxis(1)));
}
void Chassis::Engage() {
	climberShift->Set(true);
}

void Chassis::Disengage() { //Default position. Also engages the climber, but to have a Climber::Engage(), I'd have to
	climberShift->Set(false); //duplicate things, and that's not good.
}
