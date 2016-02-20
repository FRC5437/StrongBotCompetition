#include "RotateAbsoluteDegrees.h"

int degreesPOV;

RotateAbsoluteDegrees::RotateAbsoluteDegrees()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RotateAbsoluteDegrees::Initialize()
{
	degreesPOV = Robot::oi->getjoy1()->GetPOV();
	if (degreesPOV >= 180) {
		degreesPOV = ((degreesPOV + 180) % 360) - 180;
		if (degreesPOV == -180) {
			degreesPOV = 178;
		}
	}
	Robot::chassis->Enable();
	Robot::chassis->SetSetpoint(degreesPOV);
}

// Called repeatedly when this Command is scheduled to run
void RotateAbsoluteDegrees::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool RotateAbsoluteDegrees::IsFinished()
{
	return Robot::chassis->OnTarget();
}

// Called once after isFinished returns true
void RotateAbsoluteDegrees::End()
{
	Robot::chassis->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateAbsoluteDegrees::Interrupted()
{

}
