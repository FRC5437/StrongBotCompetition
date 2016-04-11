#include "AutoPos1Experimental.h"

#include "ResetYaw.h"
#include "LowerClimber.h"
#include "PrepShooter.h"
#include "EngageChassis.h"
#include "WaitDuration.h"
#include "RotateDegrees.h"
#include "CrossDefense.h"
#include "TurnRight.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "FireBoulder.h"

AutoPos1Experimental::AutoPos1Experimental()
{
	//This is a variation on the Position 1 autonomous which is meant to cross back under the low bar after shooting.
	AddParallel(new ResetYaw());
	AddParallel(new LowerClimber());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new WaitDuration(0.3));
	AddSequential(new RotateDegrees(-90));
	AddSequential(new CrossDefense(5.5));
	AddSequential(new TurnRight(1.0));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(860));
	AddSequential(new FireBoulder());
	AddParallel(new PrepShooter());
	AddSequential(new RotateDegrees(90));
	AddSequential(new CrossDefense(5.5));
}
