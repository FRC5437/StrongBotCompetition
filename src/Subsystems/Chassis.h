#ifndef Chassis_H
#define Chassis_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Chassis: public PIDSubsystem
{
private:
	std::shared_ptr<CANTalon> cANTalon1;
	std::shared_ptr<CANTalon> cANTalon2;
	std::shared_ptr<RobotDrive> robotDrive21;
	std::shared_ptr<Solenoid> climberShift;
public:
	Chassis();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Drive(double left, double right);
	void Drive(std::shared_ptr<Joystick> joy1, std::shared_ptr<Joystick> joy2);
	void DriveHigh(std::shared_ptr<Joystick> joy1, std::shared_ptr<Joystick> joy2);
	void Engage();
	void Disengage();
};

#endif
