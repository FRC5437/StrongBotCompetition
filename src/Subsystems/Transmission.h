#ifndef Transmission_H
#define Transmission_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Transmission: public Subsystem
{
private:
public:
	Transmission();
	void InitDefaultCommand();
	void HighGear();
	void LowGear();
};

#endif
