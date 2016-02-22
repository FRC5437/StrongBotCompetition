#ifndef TransmissionToggle_H
#define TransmissionToggle_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class TransmissionToggle: public Command
{
public:
	TransmissionToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
