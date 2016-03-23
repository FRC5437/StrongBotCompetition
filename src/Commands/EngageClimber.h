#ifndef EngageClimber_H
#define EngageClimber_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class EngageClimber: public Command
{
public:
	EngageClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
