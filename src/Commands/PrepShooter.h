

#ifndef PREPSHOOTER_H
#define PREPSHOOTER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class PrepShooter: public Command {
public:
	PrepShooter();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
