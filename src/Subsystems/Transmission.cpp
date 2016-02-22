#include "Transmission.h"
#include "../RobotMap.h"

std::shared_ptr<Solenoid> transmissionSolenoid;

const bool On = true;
const bool Off = false;

Transmission::Transmission() :
		Subsystem("ExampleSubsystem")
{
	transmissionSolenoid.reset(new Solenoid(0, 1));
}

void Transmission::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Transmission::Forward() {
	transmissionSolenoid->Set(On);
}

void Transmission::Reverse() {
	transmissionSolenoid->Set(Off);
}
