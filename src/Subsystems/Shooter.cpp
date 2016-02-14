// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Shooter.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Shooter::Shooter() : Subsystem("Shooter") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    doubleSolenoid1 = RobotMap::shooterDoubleSolenoid1;
    cANTalon1 = RobotMap::shooterCANTalon1;
    cANTalon2 = RobotMap::shooterCANTalon2;
    cANTalon3 = RobotMap::shooterCANTalon3;
    cANTalon4 = RobotMap::shooterCANTalon4;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Load() {
	cANTalon1->Set(0.5);
	cANTalon2->Set(-0.5);
}

void Shooter::SpinUpTheWheels() {
	cANTalon1->Set(-1.0);
	cANTalon2->Set(1.0);
}

void Shooter::Fire() {
	doubleSolenoid1->Set(DoubleSolenoid::kForward);
}

void Shooter::Stop() {
	cANTalon1->Set(0.0);
	cANTalon2->Set(0.0);
	doubleSolenoid1->Set(DoubleSolenoid::kReverse);
}
