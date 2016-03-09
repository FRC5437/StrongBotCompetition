// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Pullup.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Pullup::Pullup() : Subsystem("Pullup") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    armSolenoid1 = RobotMap::climberSolenoid1;
    armSolenoid2 = RobotMap::climberSolenoid2;
    armSolenoid3 = RobotMap::climberSolenoid3;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Pullup::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
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
