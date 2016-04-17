

#include "PrepShooter.h"


PrepShooter::PrepShooter(): Command() {
  Requires(Robot::shooterActuator.get());
	Requires(Robot::targeting.get());
	SetTimeout(3);

}

void PrepShooter::Initialize() {
}

void PrepShooter::Execute() {
	Robot::shooterActuator->Aim(Robot::oi->getjoy3()->GetRawAxis(1));
}

bool PrepShooter::IsFinished() {
	return false; //abs(Robot::shooterActuator->Actuator->GetClosedLoopError()) <= 5.0 || IsTimedOut();
}

void PrepShooter::End() {

}

void PrepShooter::Interrupted() {

}
