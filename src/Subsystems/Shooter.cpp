



#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ShooterHasBall.h"
DigitalInput* ballSensor;
Talon* ballFeeder;

Shooter::Shooter() : Subsystem("Shooter") {
    Solenoid1 = RobotMap::shooterSolenoid1;
    cANTalon1 = RobotMap::shooterCANTalon1;
    cANTalon1->Disable();
    cANTalon1->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    cANTalon1->SetSensorDirection(false);
    cANTalon1->SetInverted(true);
    cANTalon2 = RobotMap::shooterCANTalon2;
    cANTalon2->Disable();
    cANTalon2->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    cANTalon2->SetSensorDirection(false);
    cANTalon2->SetInverted(false);
    ballSensor = new DigitalInput(0);
    ballFeeder = new Talon(0);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShooterHasBall());

}

void Shooter::Load() {
	cANTalon1->Enable();
	cANTalon1->SetSetpoint(4000);
	cANTalon2->Enable();
	cANTalon2->SetSetpoint(4000);
}

void Shooter::SpinUpTheWheels() {
	cANTalon1->Enable();
	cANTalon1->SetSetpoint(-4400);
	cANTalon2->Enable();
	cANTalon2->SetSetpoint(-4400);
}

void Shooter::Fire() {
	Solenoid1->Set(true);
	SmartDashboard::PutString("Fired", "Fired");
	SmartDashboard::PutNumber("Left Velocity", cANTalon1->GetSpeed());
	SmartDashboard::PutNumber("Right Velocity", cANTalon2->GetSpeed());
	Wait(1);
	Stop();
}

void Shooter::Stop() {
	cANTalon1->Disable();
	cANTalon2->Disable();
	ballFeeder->Set(0.0);
	Solenoid1->Set(false);
}

void Shooter::Angle(double setpoint) {

}

void Shooter::Lower() {
}

void Shooter::Loadpos() {
}

void Shooter::PrepAndFire() {
	SpinUpTheWheels();
	//Wait(0.3);
	//if ((cANTalon1->GetSpeed() >= -(cANTalon2->GetSpeed() - 10.0))) {
		//if (cANTalon1->GetSpeed() <= -(cANTalon2->GetSpeed() + 10.0)) {
		//Fire();
		//}
	//}
}

double Shooter::GetRPMs() {
	return ((cANTalon1->GetSpeed() - cANTalon2->GetSpeed()) / 2.0);
}

double Shooter::GetLeftSpeed() {
	return cANTalon1->GetSpeed();
}

double Shooter::GetRightSpeed() {
	return cANTalon2->GetSpeed();
}

bool Shooter::HasBall() {
	return ballSensor->Get();
}

void Shooter::Feed() {
	ballFeeder->Set(1.0);
}

void Shooter::Eject() {
	ballFeeder->Set(-1.0);
}
