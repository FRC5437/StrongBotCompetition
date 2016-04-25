#include "CDFAutoTarLeft.h"
#include "CDFArmDropAuto.h"
#include "CrossDefense.h"
#include "TurnLeft.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "FireBoulder.h"
#include "PrepShooter.h"
#include "LowerClimber.h"
#include "CheckPitchRequirement.h"
#include "HighGear.h"
#include "RotateDegrees.h"

CDFAutoTarLeft::CDFAutoTarLeft()
{
	AddSequential(new CrossDefense(0.85));
	AddSequential(new LowerClimber());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new CrossDefense(0.6));
	AddSequential(new WaitCommand(0.25));
	AddSequential(new CheckPitchRequirement());
	AddSequential(new WaitCommand(0.25));
	AddSequential(new CrossDefense(0.75));
	AddSequential(new HighGear());
	AddSequential(new CrossDefense(0.6));
	AddSequential(new RotateDegrees(-5));
	AddSequential(new WaitCommand(0.6));
	AddSequential(new CenterOnTarget());
	//AddSequential(new FireBoulder());

}
