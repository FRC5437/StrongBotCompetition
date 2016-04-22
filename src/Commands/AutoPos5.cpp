


#include "AutoPos5.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "RotateDegrees.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "TurnLeft.h"
#include "LowerClimber.h"
#include "EngageChassis.h"




AutoPos5::AutoPos5() {

	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());


	AddSequential(new CrossDefense(5));
	AddSequential(new RotateDegrees(-30));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(840));
	AddSequential(new FireBoulder());
}
