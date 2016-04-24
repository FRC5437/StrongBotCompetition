#include "CenterOnTarget.h"
#include "Target.h"
#include "FireBoulder.h"
#include "ShooterAngleAutonomous.h"
#include "WaitDuration.h"
#include "PrepShooter.h"

CenterOnTarget::CenterOnTarget()
{

	AddSequential(new Target());
	AddSequential(new WaitCommand(0.35));
	AddSequential(new PrintCommand("CenterOnTarget - done with Target about to FireBoulder"));
	AddSequential(new FireBoulder());
	AddSequential(new WaitCommand(0.35));
	AddSequential(new PrepShooter());
}
