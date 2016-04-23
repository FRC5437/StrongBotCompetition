#ifndef CheckPitchRequirement_H
#define CheckPitchRequirement_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class CheckPitchRequirement: public Command
{
public:
	Scheduler* scheduler;
	CheckPitchRequirement();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
