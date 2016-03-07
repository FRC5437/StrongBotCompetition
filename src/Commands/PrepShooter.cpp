// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "PrepShooter.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

PrepShooter::PrepShooter(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooterActuator.get());
	Requires(Robot::targeting.get());
	SetTimeout(3);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void PrepShooter::Initialize() {
	//Robot::shooterActuator->Aim(0);
}

// Called repeatedly when this Command is scheduled to run
void PrepShooter::Execute() {
	//Robot::shooter->Angle((Robot::targeting->GetHeight() * (5.0/3.0) + 160));
	Robot::shooterActuator->Aim(70.0);
}

// Make this return true when this Command no longer needs to run execute()
bool PrepShooter::IsFinished() {
	return abs(Robot::shooterActuator->Actuator->GetClosedLoopError()) <= 5.0 || IsTimedOut();
}

// Called once after isFinished returns true
void PrepShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepShooter::Interrupted() {

}
