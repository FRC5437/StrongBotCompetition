

#include "AutoPos4.h"

#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"



AutoPos4::AutoPos4() {

	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());



	AddSequential(new CrossDefense(4));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(860));
	AddSequential(new FireBoulder());
}
