


#include "Target.h"
#include <math.h>

#define FOCAL_LENGTH 589.73
#define PI 3.14159265
#define X_RATIO 0.10  //calculated degress per pixel - probably needs refinement - may not be constant
#define Y_RATIO 0.0830

double* targetResults;
double targetDistance; //distance between camera and target
double pixelsToMove; //quite literally the difference between the two detected centers
double degreesToRotate;
double currentYaw;
const double centerX = 265.0;
const double tolX = 7.0;

bool rightDirection = true;


Target::Target(): Command() {
    Requires(Robot::targeting.get());
	Requires(Robot::chassis.get());
	Requires(Robot::navX.get());
	Requires(Robot::shooterActuator.get());
	SetTimeout(2.0);
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
	double distanceToTargetInches = 144; //(FOCAL_LENGTH * knownWidthInches)/ targetWidth;
	double moveWidthInches = (distanceToTargetInches * pixelsToMove)/FOCAL_LENGTH;

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
}

void Target::Execute() {
	SmartDashboard::PutNumber("Yaw", Robot::navX->ahrs->GetYaw());
}

bool Target::IsFinished() {
	bool result = Robot::chassis->OnTarget() || IsTimedOut();
	if (result){

	}
    return result;
}

void Target::End() {

	double finalYaw = Robot::navX->ahrs->GetYaw();
	Robot::logger->log(	"Final Yaw: " + std::to_string(finalYaw) );
	double targetX = Robot::targeting->GetTarget()[0];
	Wait(0.5);
	Robot::logger->log("Target::IsFinished targetX: " + std::to_string(targetX));

	rightDirection = true;
	Robot::chassis->Disable();
}


void Target::Interrupted() {
	Robot::chassis->Disable();
}
