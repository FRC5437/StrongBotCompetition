#include "ShooterManual.h"

ShooterManual::ShooterManual()
{
	Requires(Robot::shooter.get());
}

void ShooterManual::Initialize()
{

}

void ShooterManual::Execute()
{
	Robot::shooter->Stop();
}

bool ShooterManual::IsFinished()
{
	return false;
}

void ShooterManual::End()
{

}

void ShooterManual::Interrupted()
{

}
