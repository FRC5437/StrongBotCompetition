


#include "AutoPos3.h"

#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"



AutoPos3::AutoPos3() {

	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());


	AddSequential(new CrossDefense(4));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(840));
	AddSequential(new FireBoulder());
}
