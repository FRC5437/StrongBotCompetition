#ifndef ShooterAngleAutonomous_H
#define ShooterAngleAutonomous_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ShooterAngleAutonomous: public Command
{
private:
	double potSetting;
public:
	ShooterAngleAutonomous(double setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
