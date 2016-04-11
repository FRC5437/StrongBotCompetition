


#include "RotateDegrees.h"

int initDegrees;
int turnDegrees;
bool rightDir;


RotateDegrees::RotateDegrees(int targetDegrees): Command() {

	Requires(Robot::navX.get());
	Requires(Robot::chassis.get());
	degrees = targetDegrees;
}

void RotateDegrees::Initialize() {
	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(degrees);
}
void RotateDegrees::Execute() {

}

bool RotateDegrees::IsFinished() {
    return Robot::chassis->OnTarget();
}

void RotateDegrees::End() {
rightDir = false;
Robot::chassis->Drive(0.0,0.0);
}

void RotateDegrees::Interrupted() {

}
