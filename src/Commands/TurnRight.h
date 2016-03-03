#ifndef TurnRight_H
#define TurnRight_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class TurnRight: public Command
{
public:
	TurnRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
