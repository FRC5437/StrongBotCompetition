bool fired;

#include "FireBoulder.h"


FireBoulder::FireBoulder(): Command() {
    Requires(Robot::shooter.get());
	grip = NetworkTable::GetTable("GRIP");
}
void FireBoulder::Initialize() {
	Wait(0.3);
	fired = false;
	Robot::shooter->SpinUpTheWheels();
}
void FireBoulder::Execute() {
	SmartDashboard::PutNumber("Left Speed", Robot::shooter->GetLeftSpeed());
	SmartDashboard::PutNumber("Right Speed", -Robot::shooter->GetRightSpeed());
	if (Robot::shooter->GetLeftSpeed() > 4500.0 && -(Robot::shooter->GetRightSpeed()) > 4500.0) {
		if ((Robot::shooter->GetLeftSpeed() >= -(Robot::shooter->GetRightSpeed() + 50.0))) {
			if ((Robot::shooter->GetLeftSpeed() <= -(Robot::shooter->GetRightSpeed() - 50.0))) {
				Robot::shooter->Fire();
				auto left_rpm = std::to_string(Robot::shooter->GetLeftSpeed());
				auto right_rpm = std::to_string(Robot::shooter->GetRightSpeed());
				auto center_x = std::to_string((grip->GetNumberArray("myContoursReport/centerX", llvm::ArrayRef<double>())[1]));
				auto center_y = std::to_string((grip->GetNumberArray("myContoursReport/centerY", llvm::ArrayRef<double>())[1]));
				std::string message = "Left RPM: " + left_rpm + "   Right RPM: " + right_rpm;
				message += (" Center X:" + center_x + " Center Y:" + center_y);
				Robot::logger->log(message);
				fired = true;
			}
		}
	}
}
bool FireBoulder::IsFinished() {
    return fired;
}
void FireBoulder::End() {
	fired = false;
}
void FireBoulder::Interrupted() {

}
