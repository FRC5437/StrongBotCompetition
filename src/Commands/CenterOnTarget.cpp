#include "CenterOnTarget.h"
#include "Target.h"
#include "FireBoulder.h"
#include "ShooterAngleAutonomous.h"
#include "PrepShooter.h"

CenterOnTarget::CenterOnTarget()
{

	AddSequential(new Target());
	//Wait (0.5);
	//AddSequential (new Target());
	//Wait (0.5);
	//AddSequential (new Target());
	//Wait (1.0);
	//AddSequential (new ShooterAngleAutonomous(840));
	//Wait (3.0);
	AddSequential(new FireBoulder());
	//Wait (2.0);
	//AddSequential (new PrepShooter());
}
