#include "EjectBoulder.h"

EjectBoulder::EjectBoulder()
{
	Requires(Robot::shooter.get());
	SetTimeout(3.0);
}

void EjectBoulder::Initialize()
{

}

void EjectBoulder::Execute()
{
	Robot::shooter->Eject();
}

bool EjectBoulder::IsFinished()
{
	return IsTimedOut();
}

void EjectBoulder::End()
{
	Robot::shooter->Stop();
}

void EjectBoulder::Interrupted()
{

}
