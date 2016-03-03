#ifndef ShooterManual_H
#define ShooterManual_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ShooterManual: public Command
{
public:
	ShooterManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
