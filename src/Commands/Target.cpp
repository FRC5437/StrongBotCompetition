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
#define FOCAL_LENGTH 589.73

double* targetResults;
double targetDistance; //distance between camera and target
double centerDistance; //quite literally the difference between the two detected centers
double degreesToRotate;
double currentYaw;
const double centerX = 240.0;
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
	Requires(Robot::shooterActuator.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Target::Initialize() {
	Robot::shooterActuator->Aim(600);
	Wait(1.0);
	if (Robot::targeting->HasTarget() == false) {
		Robot::chassis->Drive(0.7, -0.7);
		Wait(0.2);
		Robot::chassis->Drive(0.0, 0.0);
		Wait(0.2);
	}
	currentYaw = Robot::navX->ahrs->GetYaw();

	targetResults = Robot::targeting->GetTarget();
	double targetX = targetResults[0];
	double targetY = targetResults[1];
	double targetWidth = targetResults[2];
	double targetHeight = targetResults[3];

	// Crockett - adjust centerDistance to the right a little - -260 instead of -280
	centerDistance = targetX - 245.0;
	double knownWidthInches = Robot::targeting->AdjustTargetWidthForSkew(targetWidth, targetHeight);
	double distanceToTargetInches = 144; //(FOCAL_LENGTH * knownWidthInches)/ targetWidth;
	double moveWidthInches = (distanceToTargetInches * centerDistance)/FOCAL_LENGTH;

	//degreesToRotate = asin(centerDistance/FOCAL_LENGTH) * 180 / PI;
	degreesToRotate = asin(moveWidthInches/distanceToTargetInches) * 180 / PI;

	Robot::logger->log(
			//Degrees to Rotate, Current Yaw, Final Degrees, Pixels off target, Center X, Distance From Target, Inches to Rotate, Perspective Width of Target, Center Y, Pixel Width, Pixel Height
		"" + std::to_string(degreesToRotate)
		+ "," + std::to_string(currentYaw)
		+ "," + std::to_string(currentYaw+degreesToRotate)
		+ "," + std::to_string(centerDistance)
		+ "," + std::to_string(targetX)
		+ "," + std::to_string(distanceToTargetInches)
		+ "," + std::to_string(moveWidthInches)
		+ "," + std::to_string(knownWidthInches)
		+ "," + std::to_string(targetY)
		+ "," + std::to_string(targetWidth)
		+ "," + std::to_string(targetHeight)
	);

	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(currentYaw+degreesToRotate);
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
	//Wait(0.35);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Target::Interrupted() {
	Robot::chassis->Disable();
}
