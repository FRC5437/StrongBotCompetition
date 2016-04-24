

#include "PrepShooter.h"


PrepShooter::PrepShooter(): Command() {
  Requires(Robot::shooterActuator.get());
	Requires(Robot::targeting.get());
	SetTimeout(3);

}

void PrepShooter::Initialize() {
}

void PrepShooter::Execute() {
	Robot::shooterActuator->Aim(108);
}

bool PrepShooter::IsFinished() {
	return abs(Robot::shooterActuator->Actuator->GetClosedLoopError()) <= 5.0 || IsTimedOut();
}

void PrepShooter::End() {

}

void PrepShooter::Interrupted() {

}
