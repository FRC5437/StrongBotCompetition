

#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shooter: public Subsystem {
private:
	std::shared_ptr<Solenoid> Solenoid1;
	std::shared_ptr<CANTalon> cANTalon1;
	std::shared_ptr<CANTalon> cANTalon2;
	//std::shared_ptr<CANTalon> cANTalon3;
public:
	Shooter();
	void InitDefaultCommand();
	void Load();
	void SpinUpTheWheels();
	void Fire();
	void Stop();
	void Angle(double setpoint);
	void Lower();
	void Loadpos();
	void PrepAndFire();
	double GetRPMs();
	double GetLeftSpeed();
	double GetRightSpeed();
	bool HasBall();
	void Feed();
	void Eject();
};

#endif
