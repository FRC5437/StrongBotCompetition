#include "CDFArmDropAuto.h"
#include "WaitDuration.h"
#include "LowerClimber.h"

CDFArmDropAuto::CDFArmDropAuto() {
	AddSequential(new WaitDuration(1.0));
	AddSequential(new LowerClimber());
}
