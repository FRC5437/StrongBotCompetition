

#ifndef DriveToDistance_H
#define DriveToDistance_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveToDistance: public Command {
public:
	DriveToDistance();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
