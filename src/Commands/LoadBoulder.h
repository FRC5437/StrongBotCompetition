

#ifndef LOADBOULDER_H
#define LOADBOULDER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class LoadBoulder: public Command {
public:
	LoadBoulder();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
