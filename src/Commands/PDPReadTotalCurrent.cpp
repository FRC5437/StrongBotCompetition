#include "PDPReadTotalCurrent.h"

PDPReadTotalCurrent::PDPReadTotalCurrent()
{
	Requires(Robot::kPDP.get());
}

void PDPReadTotalCurrent::Initialize()
{

}

void PDPReadTotalCurrent::Execute()
{
	SmartDashboard::PutNumber("Total Current", Robot::kPDP->pdp->GetTotalCurrent());
}

bool PDPReadTotalCurrent::IsFinished()
{
	return false;
}

void PDPReadTotalCurrent::End()
{

}

void PDPReadTotalCurrent::Interrupted()
{

}
