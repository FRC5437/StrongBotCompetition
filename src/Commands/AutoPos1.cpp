



#include "AutoPos1.h"
#include "../Subsystems/NavX.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "TurnRight.h"
#include "RotateDegrees.h"
#include "HighGear.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"
#include "WaitDuration.h"



AutoPos1::AutoPos1() {

	double duration_seconds = 2.0;
	double rotation_seconds = 0.6;

	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());
	AddSequential(new WaitCommand(1.0));

	AddSequential(new CrossDefense(duration_seconds));
	AddSequential(new HighGear());
	AddSequential(new CrossDefense(0.7));
	AddSequential(new WaitCommand(0.4));
	AddSequential(new PrintCommand("About to RotateDegrees..."));
	AddSequential(new RotateDegrees(40));
	AddSequential(new WaitCommand(0.4));
	AddSequential(new PrintCommand("About to CenterOnTarget..."));
	AddSequential(new CenterOnTarget());

	AddSequential(new PrepShooter());

}
