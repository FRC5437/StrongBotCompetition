

#ifndef ROTATEDEGREES_H
#define ROTATEDEGREES_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class RotateDegrees: public Command {
public:
	RotateDegrees(int targetDegrees);
	double degrees;
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
