#ifndef ShooterActuator_H
#define ShooterActuator_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class ShooterActuator: public PIDSubsystem
{
private:
public:
	ShooterActuator();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Aim(double setpoint);
	std::shared_ptr<CANTalon> Actuator;

};

#endif
