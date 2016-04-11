#include "ShooterHasBall.h"

ShooterHasBall::ShooterHasBall()
{
	Requires(Robot::shooter.get());
}

void ShooterHasBall::Initialize()
{

}

void ShooterHasBall::Execute()
{
	SmartDashboard::PutBoolean("Has Ball", Robot::shooter->HasBall());
}

bool ShooterHasBall::IsFinished()
{
	return false;
}

void ShooterHasBall::End()
{

}

void ShooterHasBall::Interrupted()
{

}
