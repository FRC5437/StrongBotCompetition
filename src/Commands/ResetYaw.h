#ifndef ResetYaw_H
#define ResetYaw_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ResetYaw: public Command
{
public:
	ResetYaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
