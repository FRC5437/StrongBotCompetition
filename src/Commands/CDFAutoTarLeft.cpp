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

	AddParallel(new CDFArmDropAuto());
	AddSequential(new CrossDefense(5.0));
	AddSequential(new TurnLeft(0.5));
	AddSequential(new CenterOnTarget());
	AddSequential(new ShooterAngleAutonomous(880));
	AddSequential(new FireBoulder());
	AddSequential(new PrepShooter());
}
