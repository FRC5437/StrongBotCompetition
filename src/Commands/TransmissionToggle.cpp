#include "TransmissionToggle.h"

bool transmissionForward = false;

TransmissionToggle::TransmissionToggle()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::transmission.get());
}

// Called just before this Command runs the first time
void TransmissionToggle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TransmissionToggle::Execute()
{
	if ((Robot::oi->getjoy1()->GetRawButton(1)) && (Robot::oi->getjoy2()->GetRawButton(1))) {
		Robot::transmission->HighGear();
	} else {
		Robot::transmission->LowGear();
	}

}

// Make this return true when this Command no longer needs to run execute()
bool TransmissionToggle::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TransmissionToggle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TransmissionToggle::Interrupted()
{

}
