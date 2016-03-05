/*
 * EaglestrikeErrorLogger.h
 *
 *  Created on: Mar 2, 2015
 *      Author: Ben Evans
 */

#ifndef LOGGING_EAGLESTRIKEERRORLOGGER_H_
#define LOGGING_EAGLESTRIKEERRORLOGGER_H_

#include "WPILib.h"
#include <fstream>

class EaglestrikeErrorLogger {
public:
	EaglestrikeErrorLogger(std::string filename);
	virtual ~EaglestrikeErrorLogger();
	void log(std::string);
private:
	std::fstream file;
};

#endif /* LOGGING_EAGLESTRIKEERRORLOGGER_H_ */
