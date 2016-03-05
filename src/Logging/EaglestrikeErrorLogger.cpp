/*
 * EaglestrikeErrorLogger.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: Ben Evans
 */

#include "EaglestrikeErrorLogger.h"

EaglestrikeErrorLogger::EaglestrikeErrorLogger(std::string filename):
file(filename, std::ios_base::app)
{

}


EaglestrikeErrorLogger::~EaglestrikeErrorLogger() {
	file.close();
}

void EaglestrikeErrorLogger::log(std::string message){
	file << message << std::endl;
}
