

#ifndef NAVX_H
#define NAVX_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "AHRS.h"

class NavX: public Subsystem {
private:
public:
	std::shared_ptr<AHRS> ahrs;
	NavX();
	void InitDefaultCommand();
	int YawGet360();
};

#endif
