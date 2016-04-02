#include "EjectBoulder.h"

EjectBoulder::EjectBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	SetTimeout(3.0);
}

// Called just before this Command runs the first time
void EjectBoulder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void EjectBoulder::Execute()
{
	Robot::shooter->Eject();
}

// Make this return true when this Command no longer needs to run execute()
bool EjectBoulder::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void EjectBoulder::End()
{
	Robot::shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EjectBoulder::Interrupted()
{

}
