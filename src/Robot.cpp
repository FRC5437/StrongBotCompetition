


#include "Robot.h"

std::shared_ptr<Chassis> Robot::chassis;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<NavX> Robot::navX;
std::shared_ptr<Targeting> Robot::targeting;
std::shared_ptr<Compressor> Robot::compressor;
std::shared_ptr<Pullup> Robot::pullup;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Transmission> Robot::transmission;
std::shared_ptr<ShooterActuator> Robot::shooterActuator;
EaglestrikeErrorLogger* Robot::logger;
std::shared_ptr<PDP> Robot::kPDP;
std::shared_ptr<SendableChooser> chooser;

void Robot::RobotInit() {
	RobotMap::init();

	logger = new EaglestrikeErrorLogger("/home/lvuser/shooter.log");
	logger->log("Initializing logger...");
	chassis.reset(new Chassis());
    shooter.reset(new Shooter());
    navX.reset(new NavX());
    targeting.reset(new Targeting());
    compressor.reset(new Compressor());
    pullup.reset(new Pullup());
    transmission.reset(new Transmission());
    shooterActuator.reset(new ShooterActuator());
    kPDP.reset(new PDP());

	oi.reset(new OI());

	chooser.reset (new SendableChooser);
	chooser->AddDefault("Position 4", new AutoPos4());
	chooser->AddObject("Position 3", new AutoPos3());
	chooser->AddObject("Position 1", new AutoPos1());
	chooser->AddObject("Position 2", new AutoPos2());
	chooser->AddObject("Position 5", new AutoPos5());
	SmartDashboard::PutData("Auto Modes", chooser.get());
  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand.reset((Command*) chooser->GetSelected());

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

