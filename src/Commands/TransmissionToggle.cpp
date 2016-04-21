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
