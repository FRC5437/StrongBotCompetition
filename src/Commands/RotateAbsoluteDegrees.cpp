#include "RotateAbsoluteDegrees.h"

int degreesPOV;

RotateAbsoluteDegrees::RotateAbsoluteDegrees()
{
	Requires(Robot::chassis.get());
}

void RotateAbsoluteDegrees::Initialize()
{
	degreesPOV = Robot::oi->getjoy1()->GetPOV();
	if (degreesPOV >= 179) {
		degreesPOV = ((degreesPOV + 180) % 360) - 180;
		if (degreesPOV < -140) {
			degreesPOV = 0;
		}
	}
	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(degreesPOV);
}

void RotateAbsoluteDegrees::Execute()
{

}

bool RotateAbsoluteDegrees::IsFinished()
{
	return Robot::chassis->OnTarget();
}

void RotateAbsoluteDegrees::End()
{
	Robot::chassis->Disable();
}

void RotateAbsoluteDegrees::Interrupted()
{

}
