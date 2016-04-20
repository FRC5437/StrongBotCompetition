

#ifndef TARGETING_H
#define TARGETING_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Targeting: public Subsystem {
private:
	std::shared_ptr<NetworkTable> grip;
public:
	double targetx;
	Targeting();
	void InitDefaultCommand();
	double* GetTarget();
	double GetDistance();
	double GetHeight();
	double AdjustTargetingBasedOnArea(double width, double height);
	bool OnTargetX( double centerX );
	double TargetX();
	double TargetY();
	bool HasTarget();
};

#endif
