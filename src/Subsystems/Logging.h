#ifndef Logging_H
#define Logging_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Logging: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Logging();
	void InitDefaultCommand();
	void AddHeaders(std::vector<std::string> headers);
	void AddData();
	void AddHeaders();
};

#endif
