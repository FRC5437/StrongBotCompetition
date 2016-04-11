



#include "AutoPos1.h"
#include "../Subsystems/NavX.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "TurnRight.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"
#include "WaitDuration.h"



AutoPos1::AutoPos1() {

	double duration_seconds = 5.5;
	double rotation_seconds = 1.0;

	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());
	AddSequential(new WaitDuration(1.5));

	AddSequential(new CrossDefense(duration_seconds));
	AddSequential(new TurnRight(rotation_seconds));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(860));
	AddSequential(new FireBoulder());

	AddSequential(new PrepShooter());

}
