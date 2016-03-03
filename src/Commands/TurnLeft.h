#ifndef TurnLeft_H
#define TurnLeft_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class TurnLeft: public Command
{
public:
	TurnLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
