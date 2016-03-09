#ifndef LowerClimber_H
#define LowerClimber_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class LowerClimber: public Command
{
public:
	LowerClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
