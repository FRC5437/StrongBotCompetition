#ifndef ShooterHasBall_H
#define ShooterHasBall_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class ShooterHasBall: public Command
{
public:
	ShooterHasBall();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
