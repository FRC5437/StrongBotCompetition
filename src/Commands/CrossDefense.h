

#ifndef CROSSDEFENSE_H
#define CROSSDEFENSE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class CrossDefense: public Command {
public:
	CrossDefense(double time);

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
