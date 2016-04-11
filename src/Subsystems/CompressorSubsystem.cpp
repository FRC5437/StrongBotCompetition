



#include "CompressorSubsystem.h"
#include "../RobotMap.h"


CompressorSubsystem::CompressorSubsystem() : Subsystem("CompressorSubsystem") {
    compressor1 = RobotMap::compressorCompressor1;
}

void CompressorSubsystem::InitDefaultCommand() {

}

