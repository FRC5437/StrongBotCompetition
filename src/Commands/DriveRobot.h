

#ifndef DRIVEROBOT_H
#define DRIVEROBOT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DriveRobot: public Command {
public:
	DriveRobot();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

};

#endif
