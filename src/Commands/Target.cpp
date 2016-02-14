// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Target.h"

double targetX;
const double centerX = 120.0;
const double tolX = 20.0;

bool targeted;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Target::Target(): Command() {
	targeted = false;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::targeting.get());
	Requires(Robot::chassis.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Target::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Target::Execute() {
	targetX = Robot::targeting->GetTarget();

	if (targetX > centerX + tolX) {
		Robot::chassis->Drive(0.5, -0.5);
	} else if (targetX < centerX - tolX) {
		Robot::chassis->Drive(-0.5, 0.5);
	} else if ((targetX < centerX + tolX) && (targetX > centerX - tolX)) {
		Robot::chassis->Drive(0.0, 0.0);
		targeted = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Target::IsFinished() {
    return targeted;
}

// Called once after isFinished returns true
void Target::End() {
	targeted = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Target::Interrupted() {

}
