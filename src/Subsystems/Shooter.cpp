// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Shooter.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ShooterHasBall.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
DigitalInput* ballSensor;
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Shooter::Shooter() : Subsystem("Shooter") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    Solenoid1 = RobotMap::shooterSolenoid1;
    cANTalon1 = RobotMap::shooterCANTalon1;
    cANTalon1->Disable();
    cANTalon1->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    cANTalon1->SetSensorDirection(true);
    cANTalon1->SetInverted(true);
    cANTalon2 = RobotMap::shooterCANTalon2;
    cANTalon2->Disable();
    cANTalon2->SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
    cANTalon2->SetSensorDirection(true);
    cANTalon2->SetInverted(false);
    ballSensor = new DigitalInput(0);
    /*cANTalon3 = RobotMap::shooterCANTalon3;
    cANTalon3->Disable();
    cANTalon3->SetFeedbackDevice(CANTalon::AnalogPot);*/
    //cANTalon3->ConfigPotentiometerTurns(10);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Shooter::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterHasBall());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::Load() {
	cANTalon1->Enable();
	cANTalon1->SetSetpoint(4000);
	cANTalon2->Enable();
	cANTalon2->SetSetpoint(4000);
}

void Shooter::SpinUpTheWheels() {
	cANTalon1->Enable();
	cANTalon1->SetSetpoint(-5000);
	cANTalon2->Enable();
	cANTalon2->SetSetpoint(-5000);
}

void Shooter::Fire() {
	Solenoid1->Set(true);
	SmartDashboard::PutString("Fired", "Fired");
	SmartDashboard::PutNumber("Left Velocity", cANTalon1->GetSpeed());
	SmartDashboard::PutNumber("Right Velocity", cANTalon2->GetSpeed());
	//SmartDashboard::PutNumber("Shooter Position", cANTalon3->GetPosition());
	Wait(1);
	Stop();
}

void Shooter::Stop() {
	cANTalon1->Disable();
	cANTalon2->Disable();
	//cANTalon3->Disable();
	//cANTalon3->Disable();
	//cANTalon3->Set(0.0);
	Solenoid1->Set(false);
}

void Shooter::Angle(double setpoint) {

	//int angle = ((atan(95/setpoint) * 180 / 3.14159265) * 15.0) + 240;
	//SmartDashboard::PutNumber("Angle", angle);
	//cANTalon3->Enable();
    //cANTalon3->SetSetpoint(angle);
	//cANTalon3->Set(setpoint);




	//cANTalon3->Set(joystick);
}

void Shooter::Lower() {
	//cANTalon3->Enable();
	//cANTalon3->SetSetpoint(200);
}

void Shooter::Loadpos() {
	//cANTalon3->Enable();
	//cANTalon3->SetSetpoint(138);
}

void Shooter::PrepAndFire() {
	SpinUpTheWheels();
	Wait(0.3);
	if ((cANTalon1->GetSpeed() >= -(cANTalon2->GetSpeed() - 10.0))) {
		if (cANTalon1->GetSpeed() <= -(cANTalon2->GetSpeed() + 10.0)) {
		Fire();
		}
	}
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
	ballSensor->Get();
}

