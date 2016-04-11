#ifndef PDP_H
#define PDP_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PDP: public Subsystem
{
private:
public:
	std::shared_ptr<PowerDistributionPanel> pdp;
	PDP();
	void InitDefaultCommand();
};

#endif
