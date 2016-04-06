#ifndef WaitDuration_H
#define WaitDuration_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class WaitDuration: public Command
{
public:
	WaitDuration(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
