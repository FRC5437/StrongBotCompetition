



#include "NavX.h"
#include "../RobotMap.h"

NavX::NavX() : Subsystem("NavX") {
	ahrs.reset (new AHRS(SPI::Port::kMXP));
	ahrs->Reset();
}

void NavX::InitDefaultCommand() {
}


int NavX::YawGet360() {
	int yaw = int (ahrs->GetYaw() + 180);
	return yaw;
}

