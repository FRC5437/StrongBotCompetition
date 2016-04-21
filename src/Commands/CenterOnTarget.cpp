#include "CenterOnTarget.h"
#include "Target.h"
#include "FireBoulder.h"
#include "ShooterAngleAutonomous.h"
#include "PrepShooter.h"

CenterOnTarget::CenterOnTarget()
{

	AddSequential(new Target());
	Wait (0.5);
	AddSequential(new FireBoulder());
}
