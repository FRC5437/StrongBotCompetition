#ifndef Transmission_H
#define Transmission_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Transmission: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Transmission();
	void InitDefaultCommand();
	void HighGear();
	void LowGear();
};

#endif
