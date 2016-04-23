#include "CDFAutoTarLeft.h"
#include "CDFArmDropAuto.h"
#include "CrossDefense.h"
#include "TurnLeft.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "FireBoulder.h"
#include "PrepShooter.h"
#include "LowerClimber.h"

CDFAutoTarLeft::CDFAutoTarLeft()
{
	AddSequential(new CrossDefense(1.10));
	AddSequential(new LowerClimber());
	AddSequential(new WaitCommand(1.5));
	AddSequential(new CrossDefense(0.5));
	//AddSequential(new CenterOnTarget());
}
