#ifndef PDPReadTotalCurrent_H
#define PDPReadTotalCurrent_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class PDPReadTotalCurrent: public Command
{
public:
	PDPReadTotalCurrent();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
