#include "FeedBoulder.h"

FeedBoulder::FeedBoulder()
{
	Requires(Robot::shooter.get());
	SetTimeout(3.0);
}

void FeedBoulder::Initialize()
{

}

void FeedBoulder::Execute()
{
	Robot::shooter->Feed();
}

bool FeedBoulder::IsFinished()
{
	return IsTimedOut();
}

void FeedBoulder::End()
{
	Robot::shooter->Stop();
}

void FeedBoulder::Interrupted()
{

}
