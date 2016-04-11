

#include "DriveToDistance.h"

const double TARGET_DISTANCE = 132; //inches
const double DISTANCE_TOLERANCE = 2.0; //inches


DriveToDistance::DriveToDistance(): Command() {
   Requires(Robot::chassis.get());
	Requires(Robot::targeting.get());
}

void DriveToDistance::Initialize() {

}

void DriveToDistance::Execute() {
	Robot::chassis->Drive(0.5, 0.5);
	SmartDashboard::PutNumber("Distance from target", Robot::targeting->GetDistance());

}

bool DriveToDistance::IsFinished() {
    return ((TARGET_DISTANCE + DISTANCE_TOLERANCE > Robot::targeting->GetDistance()) && (TARGET_DISTANCE - DISTANCE_TOLERANCE < Robot::targeting->GetDistance()));
}

void DriveToDistance::End() {
	Robot::chassis->Drive(0.0, 0.0);
}

void DriveToDistance::Interrupted() {

}
