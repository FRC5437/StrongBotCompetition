#include "FeedBoulder.h"

FeedBoulder::FeedBoulder()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooter.get());
	SetTimeout(3.0);
}

// Called just before this Command runs the first time
void FeedBoulder::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FeedBoulder::Execute()
{
	Robot::shooter->Feed();
}

// Make this return true when this Command no longer needs to run execute()
bool FeedBoulder::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void FeedBoulder::End()
{
	Robot::shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeedBoulder::Interrupted()
{

}
