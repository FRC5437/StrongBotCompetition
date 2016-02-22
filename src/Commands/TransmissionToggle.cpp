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
	if (transmissionForward == false) {
		Robot::transmission->Forward();
		transmissionForward = true;
	} else {
		Robot::transmission->Reverse();
		transmissionForward = false;
	}
}

// Called repeatedly when this Command is scheduled to run
void TransmissionToggle::Execute()
{

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
