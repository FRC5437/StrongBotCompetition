#ifndef BeginLogging_H
#define BeginLogging_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class BeginLogging: public Command
{
public:
	BeginLogging();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
