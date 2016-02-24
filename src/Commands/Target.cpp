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
#include <math.h>

#define PI 3.14159265

double targetX;
double targetDistance; //distance between camera and target
double centerDistance; //quite literally the difference between the two detected centers
double degreesToRotate;
double currentYaw;
const double centerX = 360.0;
const double tolX = 7.0;

bool rightDirection = true;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Target::Target(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::targeting.get());
	Requires(Robot::chassis.get());
	Requires(Robot::navX.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Target::Initialize() {
	currentYaw = Robot::navX->ahrs->GetYaw();
	targetX = Robot::targeting->GetTarget();
	centerDistance = targetX - 320.0;
	degreesToRotate = atan(centerDistance/595) * 180 / PI; //595 = focal length
	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(currentYaw + degreesToRotate);
}

// Called repeatedly when this Command is scheduled to run
void Target::Execute() {
	SmartDashboard::PutNumber("Yaw", Robot::navX->ahrs->GetYaw());
}

// Make this return true when this Command no longer needs to run execute()
bool Target::IsFinished() {
    return Robot::chassis->OnTarget();
}

// Called once after isFinished returns true
void Target::End() {
	rightDirection = true;
	Robot::chassis->Disable();
	Wait(0.35);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Target::Interrupted() {
	Robot::chassis->Disable();
}
