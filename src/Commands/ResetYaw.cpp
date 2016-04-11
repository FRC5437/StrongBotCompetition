#include "ResetYaw.h"

ResetYaw::ResetYaw(): Command()
{
	Requires(Robot::navX.get());
	SetTimeout(1);
}

void ResetYaw::Initialize()
{
	Robot::navX->ahrs->ZeroYaw();
}

void ResetYaw::Execute()
{

}

bool ResetYaw::IsFinished()
{
	return IsTimedOut();
}

void ResetYaw::End()
{

}

void ResetYaw::Interrupted()
{

}
