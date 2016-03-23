#ifndef EngageChassis_H
#define EngageChassis_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class EngageChassis: public Command
{
public:
	EngageChassis();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
