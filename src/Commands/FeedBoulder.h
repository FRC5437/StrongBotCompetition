#ifndef FeedBoulder_H
#define FeedBoulder_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class FeedBoulder: public Command
{
public:
	FeedBoulder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
