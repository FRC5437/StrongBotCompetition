

#include "DriveRobot.h"


DriveRobot::DriveRobot(): Command() {
	Requires(Robot::chassis.get());
}

void DriveRobot::Initialize() {
	Robot::chassis->Engage();
}

void DriveRobot::Execute() {
	if (Robot::oi->getjoy1()->GetRawButton(1) && Robot::oi->getjoy2()->GetRawButton(1)) {
		Robot::chassis->DriveHigh(Robot::oi->getjoy1(), Robot::oi->getjoy2());
	} else {
		Robot::chassis->Drive(Robot::oi->getjoy1(), Robot::oi->getjoy2());
	}
	SmartDashboard::PutNumber("Yaw", Robot::navX->ahrs->GetYaw());
	SmartDashboard::PutNumber("Pitch", Robot::navX->ahrs->GetPitch());
	SmartDashboard::PutNumber("Roll", Robot::navX->ahrs->GetRoll());
	SmartDashboard::PutNumber("X", Robot::navX->ahrs->GetRawGyroX());
	SmartDashboard::PutNumber("Y", Robot::navX->ahrs->GetRawGyroY());
	SmartDashboard::PutNumber("Z", Robot::navX->ahrs->GetRawGyroZ());
	SmartDashboard::PutNumber("POV", Robot::oi->getjoy1()->GetPOV());
}

bool DriveRobot::IsFinished() {
    return false;
}

void DriveRobot::End() {

}

void DriveRobot::Interrupted() {

}
