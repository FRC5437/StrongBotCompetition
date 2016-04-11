

#ifndef _ROBOT_H
#define _ROBOT_H

#include "Subsystems/CompressorSubsystem.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Logging/EaglestrikeErrorLogger.h"

#include "Subsystems/Chassis.h"
#include "Subsystems/NavX.h"
#include "Subsystems/Pullup.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Targeting.h"
#include "Subsystems/Transmission.h"
#include "Subsystems/ShooterActuator.h"
#include "Subsystems/PDP.h"

#include "OI.h"
#include "Commands/AutoPos1.h"
#include "Commands/AutoPos2.h"
#include "Commands/AutoPos3.h"
#include "Commands/AutoPos4.h"
#include "Commands/AutoPos5.h"

class Robot : public IterativeRobot {
public:
	static EaglestrikeErrorLogger* logger;

	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

    static std::shared_ptr<Chassis> chassis;
    static std::shared_ptr<Shooter> shooter;
    static std::shared_ptr<NavX> navX;
    static std::shared_ptr<Targeting> targeting;
    static std::shared_ptr<Compressor> compressor;
    static std::shared_ptr<Pullup> pullup;
    static std::shared_ptr<Transmission> transmission;
    static std::shared_ptr<ShooterActuator> shooterActuator;
    static std::shared_ptr<PDP> kPDP;
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
