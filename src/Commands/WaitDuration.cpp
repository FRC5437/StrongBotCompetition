#include "WaitDuration.h"

WaitDuration::WaitDuration(double time)
{
	SetTimeout(time);
}

void WaitDuration::Initialize()
{

}

void WaitDuration::Execute()
{

}

bool WaitDuration::IsFinished()
{
	return IsTimedOut();
}

void WaitDuration::End()
{

}

void WaitDuration::Interrupted()
{

}
