#ifndef RaiseClimber_H
#define RaiseClimber_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class RaiseClimber: public Command
{
public:
	RaiseClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
