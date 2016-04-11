

#include "Climb.h"


Climb::Climb(): Command() {

	Requires(Robot::chassis.get());
	Requires(Robot::pullup.get());
}

void Climb::Initialize() {
	Robot::chassis->Disengage();
	Robot::pullup->Climb();
}

void Climb::Execute() {
Robot::chassis->Drive(Robot::oi->getjoy3()->GetY(), Robot::oi->getjoy3()->GetY());
}

bool Climb::IsFinished() {
    return false;
}

void Climb::End() {

}

void Climb::Interrupted() {

}
