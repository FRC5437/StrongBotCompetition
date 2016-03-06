/*
 * EaglestrikeErrorLogger.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: Ben Evans
 */

#include "EaglestrikeErrorLogger.h"
#include <ctime>

EaglestrikeErrorLogger::EaglestrikeErrorLogger(std::string filename):
file(filename, std::ios_base::app)
{

}


EaglestrikeErrorLogger::~EaglestrikeErrorLogger() {
	file.close();
}

void EaglestrikeErrorLogger::log(std::string message){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  std::string str(buffer);

  file << str << " - " << message << std::endl;
}
