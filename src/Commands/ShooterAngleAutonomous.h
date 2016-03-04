#ifndef ShooterAngleAutonomous_H
#define ShooterAngleAutonomous_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ShooterAngleAutonomous: public Command
{
public:
	ShooterAngleAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
