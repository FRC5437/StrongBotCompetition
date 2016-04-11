



#include "Pullup.h"
#include "../RobotMap.h"
Pullup::Pullup() : Subsystem("Pullup") {
    armSolenoid1 = RobotMap::climberSolenoid1;
    armSolenoid2 = RobotMap::climberSolenoid2;
    armSolenoid3 = RobotMap::climberSolenoid3;
}

void Pullup::InitDefaultCommand() {
}


void Pullup::Drop() {
	armSolenoid2->Set(true);
}

void Pullup::Raise() {
	armSolenoid2->Set(false);
}

void Pullup::Segment1() {
	armSolenoid1->Set(true);
}

void Pullup::Segment2() {
	armSolenoid2->Set(false);
}

void Pullup::Segment3() {
	armSolenoid3->Set(true);
}

void Pullup::Climb() {
	armSolenoid2->Set(true);
	Wait(3.0);
	armSolenoid3->Set(false);
	armSolenoid1->Set(false);
	//TODO: add motors for climbing
}

bool Pullup::CheckState() {
	return armSolenoid2->Get();
}
