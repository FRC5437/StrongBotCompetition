#ifndef EjectBoulder_H
#define EjectBoulder_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class EjectBoulder: public Command
{
public:
	EjectBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
