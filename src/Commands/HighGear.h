#ifndef HighGear_H
#define HighGear_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class HighGear: public Command
{
public:
	HighGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
