

#include "CrossDefense.h"


CrossDefense::CrossDefense(double time): Command() {
 Requires(Robot::chassis.get());
	SetTimeout(time);
}

void CrossDefense::Initialize() {
}

void CrossDefense::Execute() {
	Robot::chassis->Drive(1.0, 1.0);
}

bool CrossDefense::IsFinished() {
    return IsTimedOut();
}

void CrossDefense::End() {
	Robot::chassis->Drive(0.0, 0.0);
}


void CrossDefense::Interrupted() {

}
