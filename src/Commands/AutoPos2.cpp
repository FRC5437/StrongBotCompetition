


#include "AutoPos2.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "TurnRight.h"
#include "FireBoulder.h"
#include "RotateDegrees.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"





AutoPos2::AutoPos2() {
	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());


	AddSequential(new CrossDefense(4.0));
	AddSequential(new TurnRight(0.8));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(860));
	AddSequential(new FireBoulder());
}
