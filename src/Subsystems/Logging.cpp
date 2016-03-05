#include "Logging.h"
#include "../RobotMap.h"
#include "../Logging/Logger.h"
#include "../Commands/BeginLogging.h"
#include "../Robot.h"

std::shared_ptr<Logger> logger;

Logging::Logging() :
		Subsystem("ExampleSubsystem")
{
	logger.reset(new Logger("/home/lvuser/shooter.log"));
}

void Logging::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new BeginLogging());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Logging::AddHeaders(std::vector<std::string> headers) {
	logger->writeHeader(headers);
}

void Logging::AddData() { //Likely need to find a better way to do this
	std::vector<double> data;
	data.push_back(Robot::shooter->GetLeftSpeed());
	data.push_back(Robot::shooter->GetRightSpeed());
	data.push_back(Robot::shooterActuator->Actuator->GetPosition());
	data.push_back(Robot::targeting->TargetX());
	data.push_back(Robot::targeting->TargetY());
	logger->writeData(data);
}

void Logging::AddHeaders() { //Command to be used until I find a better way to implement this
	std::vector<std::string> headers;
	headers.push_back("Left Motor RPMs");
	headers.push_back("Right Motor RPMs");
	headers.push_back("Shooter Actuator Position");
	headers.push_back("Center X");
	headers.push_back("Center Y");
	logger->writeHeader(headers);
}
