#include "CDFAutoTarLeft.h"
#include "CDFArmDropAuto.h"
#include "CrossDefense.h"
#include "TurnLeft.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "FireBoulder.h"
#include "PrepShooter.h"

CDFAutoTarLeft::CDFAutoTarLeft()
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddParallel(new CDFArmDropAuto());
	AddSequential(new CrossDefense(5.0));
	AddSequential(new TurnLeft(0.5));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(880));
	AddSequential(new FireBoulder());
	AddSequential(new PrepShooter());
}
