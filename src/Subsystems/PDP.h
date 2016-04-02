#ifndef PDP_H
#define PDP_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PDP: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	std::shared_ptr<PowerDistributionPanel> pdp;
	PDP();
	void InitDefaultCommand();
};

#endif
