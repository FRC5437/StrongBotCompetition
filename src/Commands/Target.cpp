


#include "Target.h"
#include <math.h>

#define FOCAL_LENGTH 589.73
#define PI 3.14159265
#define X_RATIO 0.11  //calculated degress per pixel - probably needs refinement - may not be constant
#define Y_RATIO 0.0830

double* targetResults;
double targetDistance; //distance between camera and target
double pixelsToMove; //quite literally the difference between the two detected centers
double degreesToRotate;
double currentYaw;
const double centerX = 255.0;
const double tolX = 7.0;

bool rightDirection = true;


Target::Target(): Command() {
    Requires(Robot::targeting.get());
	Requires(Robot::chassis.get());
	Requires(Robot::navX.get());
	Requires(Robot::shooterActuator.get());
}
void Target::Initialize() {
	//Robot::shooterActuator->Aim(600);
	//Wait(1.0);
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

	pixelsToMove = targetX - centerX;
	degreesToRotate = pixelsToMove * X_RATIO;
	//degreesToRotate = asin(moveWidthInches/distanceToTargetInches) * 180 / PI;

	Robot::logger->log(
			//Degrees to Rotate, Current Yaw, Final Degrees, Pixels off target, Center X, Distance From Target, Inches to Rotate, Perspective Width of Target, Center Y, Pixel Width, Pixel Height
		"" + std::to_string(degreesToRotate)
		+ "," + std::to_string(currentYaw)
		+ "," + std::to_string(currentYaw+degreesToRotate)
		+ "," + std::to_string(pixelsToMove)
		+ "," + std::to_string(targetX)
		+ "," + std::to_string(targetY)
		+ "," + std::to_string(targetWidth)
		+ "," + std::to_string(targetHeight)
	    + "," + std::to_string(X_RATIO)
	);

	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(currentYaw+degreesToRotate);
	//Robot::shooterActuator->Aim(840);
	if (OnCenterX()){
		Robot::logger->log("Target believes it is now OnTarget - fire!");
		Robot::shooterActuator->Aim(840 + Robot::targeting->AdjustTargetingBasedOnArea(targetWidth, targetHeight));
	}
}

void Target::Execute() {
	SmartDashboard::PutNumber("Yaw", Robot::navX->ahrs->GetYaw());
	//One-button targeting - if target is not made, target again. When the target is centered, raise the shooter.
		//Robot::shooterActuator->Aim(840);
	if (Robot::chassis->OnTarget()) { //Checks if the PID subsystem is where we told it to go. Doesn't mean it's where we WANT it to go.
		Robot::chassis->Disable();
		Wait(0.5);
		if (OnCenterX() == false) {
			Retarget();
		} else {
			targetResults = Robot::targeting->GetTarget();
			double targetWidth = targetResults[2];
			double targetHeight = targetResults[3];
			Robot::logger->log("Target believes it is now OnTarget - fire!");
			Robot::shooterActuator->Aim(840 + Robot::targeting->AdjustTargetingBasedOnArea(targetWidth, targetHeight));
		}
	}
}

bool Target::IsFinished() {
	bool result = OnCenterX();
    return result;
}

bool Target::OnCenterX() {
	return Robot::targeting->OnTargetX(centerX);
}

void Target::End() {
	rightDirection = true;
	Robot::chassis->Disable();
}


void Target::Interrupted() {
	Robot::chassis->Disable();
}

void Target::Retarget() {
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

	pixelsToMove = targetX - centerX;
	degreesToRotate = pixelsToMove * X_RATIO;
	//degreesToRotate = asin(moveWidthInches/distanceToTargetInches) * 180 / PI;

	Robot::logger->log(
			//Degrees to Rotate, Current Yaw, Final Degrees, Pixels off target, Center X, Distance From Target, Inches to Rotate, Perspective Width of Target, Center Y, Pixel Width, Pixel Height
			"" + std::to_string(degreesToRotate)
	+ "," + std::to_string(currentYaw)
	+ "," + std::to_string(currentYaw+degreesToRotate)
	+ "," + std::to_string(pixelsToMove)
	+ "," + std::to_string(targetX)
	+ "," + std::to_string(targetY)
	+ "," + std::to_string(targetWidth)
	+ "," + std::to_string(targetHeight)
	+ "," + std::to_string(X_RATIO)
	);

	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(currentYaw+degreesToRotate);
}
