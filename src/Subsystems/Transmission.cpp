#include "Transmission.h"
#include "../RobotMap.h"
#include "../Commands/TransmissionToggle.h"

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
	//SetDefaultCommand(new TransmissionToggle());
}

void Transmission::HighGear() {
	transmissionSolenoid->Set(On);
}

void Transmission::LowGear() {
	transmissionSolenoid->Set(Off);
}
