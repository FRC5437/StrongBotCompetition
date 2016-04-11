

#ifndef PULLUP_H
#define PULLUP_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pullup: public Subsystem {
private:
	std::shared_ptr<Solenoid> armSolenoid1;
	std::shared_ptr<Solenoid> armSolenoid2;
	std::shared_ptr<Solenoid> armSolenoid3;
public:
	Pullup();
	void InitDefaultCommand();
	void Drop();
	void Raise();
	void Segment1();
	void Segment2();
	void Segment3();
	void Climb();
	bool CheckState();
};

#endif
