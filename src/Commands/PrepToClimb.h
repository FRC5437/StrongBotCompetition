

#ifndef PREPTOCLIMB_H
#define PREPTOCLIMB_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class PrepToClimb: public Command {
public:
	PrepToClimb();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
