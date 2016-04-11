

#include "PrepToClimb.h"

bool ready = false;


PrepToClimb::PrepToClimb(): Command() {
 Requires(Robot::pullup.get());
	Requires(Robot::chassis.get());
}

void PrepToClimb::Initialize() {
	if (Robot::pullup->CheckState() == false) {
		Robot::pullup->Drop();
		Wait(1.0);
	}
}

void PrepToClimb::Execute() {
	Robot::chassis->Drive(-0.5, -0.5);
	Robot::pullup->Segment2();
	Robot::pullup->Segment1();
	Wait(4.0);
	Robot::pullup->Segment3();
	Wait(1.0);
	ready = true;
}

bool PrepToClimb::IsFinished() {
    return ready;
}

void PrepToClimb::End() {
	ready = false;
	Robot::chassis->Drive(0.0, 0.0);
}

void PrepToClimb::Interrupted() {

}
