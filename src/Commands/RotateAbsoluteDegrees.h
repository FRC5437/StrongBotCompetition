#ifndef RotateAbsoluteDegrees_H
#define RotateAbsoluteDegrees_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class RotateAbsoluteDegrees: public Command
{
public:
	RotateAbsoluteDegrees();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
