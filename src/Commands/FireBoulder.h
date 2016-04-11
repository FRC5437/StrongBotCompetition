


#ifndef FIREBOULDER_H
#define FIREBOULDER_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class FireBoulder: public Command {
public:
	FireBoulder();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

private:

	std::shared_ptr<NetworkTable> grip;

};

#endif
