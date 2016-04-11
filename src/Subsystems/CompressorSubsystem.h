

#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class CompressorSubsystem: public Subsystem {
private:
std::shared_ptr<Compressor> compressor1;
public:
	CompressorSubsystem();
	void InitDefaultCommand();

};

#endif
