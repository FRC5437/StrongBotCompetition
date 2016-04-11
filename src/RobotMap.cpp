

#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<CANTalon> RobotMap::chassisCANTalon1;
std::shared_ptr<CANTalon> RobotMap::chassisCANTalon2;
std::shared_ptr<RobotDrive> RobotMap::chassisRobotDrive21;
std::shared_ptr<Solenoid> RobotMap::shooterSolenoid1;
std::shared_ptr<CANTalon> RobotMap::shooterCANTalon1;
std::shared_ptr<CANTalon> RobotMap::shooterCANTalon2;
std::shared_ptr<CANTalon> RobotMap::shooterCANTalon3;
std::shared_ptr<Compressor> RobotMap::compressorCompressor1;
std::shared_ptr<Solenoid>RobotMap::climberSolenoid1;
std::shared_ptr<Solenoid>RobotMap::climberSolenoid2;
std::shared_ptr<Solenoid>RobotMap::climberSolenoid3;

std::shared_ptr<CANTalon> RobotMap::chassisCANTalon3;
std::shared_ptr<CANTalon> RobotMap::chassisCANTalon4;


void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    chassisCANTalon1.reset(new CANTalon(1));
    lw->AddActuator("Chassis", "CAN Talon 1", chassisCANTalon1);
    
    chassisCANTalon2.reset(new CANTalon(2));
    lw->AddActuator("Chassis", "CAN Talon 2", chassisCANTalon2);
    
    chassisRobotDrive21.reset(new RobotDrive(chassisCANTalon1, chassisCANTalon2));
    
    chassisRobotDrive21->SetSafetyEnabled(false);
        chassisRobotDrive21->SetExpiration(0.1);
        chassisRobotDrive21->SetSensitivity(0.5);
        chassisRobotDrive21->SetMaxOutput(1.0);

    shooterSolenoid1.reset(new Solenoid(0, 0));
    lw->AddActuator("Shooter", "Solenoid 1", shooterSolenoid1);
    
    shooterCANTalon1.reset(new CANTalon(5));
    shooterCANTalon1->SetControlMode(CANSpeedController::kSpeed);
    shooterCANTalon1->SetPID(0.04, 0.0, 0.0, 0.0252);
    lw->AddActuator("Shooter", "CAN Talon 1", shooterCANTalon1);
    
    shooterCANTalon2.reset(new CANTalon(6));
    shooterCANTalon2->SetControlMode(CANSpeedController::kSpeed);
    shooterCANTalon2->SetPID(0.04, 0.0, 0.0, 0.0251);
    lw->AddActuator("Shooter", "CAN Talon 2", shooterCANTalon2);
    
    shooterCANTalon3.reset(new CANTalon(7));
    shooterCANTalon3->ConfigFwdLimitSwitchNormallyOpen(false);
    shooterCANTalon3->ConfigRevLimitSwitchNormallyOpen(false);
    shooterCANTalon3->SetControlMode(CANSpeedController::kPosition);
    lw->AddActuator("Shooter", "CAN Talon 3", shooterCANTalon3);
    
    compressorCompressor1.reset(new Compressor(0));
    
    climberSolenoid1.reset(new Solenoid(0, 2));
    climberSolenoid2.reset(new Solenoid(0, 3));
    climberSolenoid3.reset(new Solenoid(0, 4));


    chassisCANTalon3.reset(new CANTalon(3));
    chassisCANTalon3->SetControlMode(CANTalon::kFollower);
    chassisCANTalon3->Set(1);
    chassisCANTalon4.reset(new CANTalon(4));
    chassisCANTalon4->SetControlMode(CANTalon::kFollower);
    chassisCANTalon4->Set(2);
}
