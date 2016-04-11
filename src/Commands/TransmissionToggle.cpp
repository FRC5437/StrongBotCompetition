#include "TransmissionToggle.h"

bool transmissionForward = false;

TransmissionToggle::TransmissionToggle()
{
	Requires(Robot::transmission.get());
}

void TransmissionToggle::Initialize()
{

}

void TransmissionToggle::Execute()
{
	if ((Robot::oi->getjoy1()->GetRawButton(1)) && (Robot::oi->getjoy2()->GetRawButton(1))) {
		Robot::transmission->HighGear();
	} else {
		Robot::transmission->LowGear();
	}

}

bool TransmissionToggle::IsFinished()
{
	return false;
}

void TransmissionToggle::End()
{

}

void TransmissionToggle::Interrupted()
{

}
