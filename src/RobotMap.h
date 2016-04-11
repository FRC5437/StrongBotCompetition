

#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"


class RobotMap {
public:
	static std::shared_ptr<CANTalon> chassisCANTalon1;
	static std::shared_ptr<CANTalon> chassisCANTalon2;
	static std::shared_ptr<RobotDrive> chassisRobotDrive21;
	static std::shared_ptr<Solenoid> shooterSolenoid1;
	static std::shared_ptr<CANTalon> shooterCANTalon1;
	static std::shared_ptr<CANTalon> shooterCANTalon2;
	static std::shared_ptr<CANTalon> shooterCANTalon3;
	static std::shared_ptr<Compressor> compressorCompressor1;
	static std::shared_ptr<Solenoid> climberSolenoid1;
	static std::shared_ptr<Solenoid> climberSolenoid2;
	static std::shared_ptr<Solenoid> climberSolenoid3;

	static std::shared_ptr<CANTalon> chassisCANTalon3;
	static std::shared_ptr<CANTalon> chassisCANTalon4;

	static void init();
};
#endif
