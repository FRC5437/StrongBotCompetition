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
#include "ResetYaw.h"

CDFAutoTarLeft::CDFAutoTarLeft()
{
	const int defaultDegreesToRotate = -5;
	int degreesToRotate = Preferences::GetInstance()->GetInt("configCDFRotateAngle", defaultDegreesToRotate);
	Robot::logger->log("Updating from preferences configCDFRotateAngle - degreesToRotate: " + std::to_string(degreesToRotate));


	AddSequential(new ResetYaw());
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
	AddSequential(new WaitCommand(0.6));
	AddSequential(new RotateDegrees(degreesToRotate));
	AddSequential(new WaitCommand(0.6));
	AddSequential(new CenterOnTarget());
	//AddSequential(new FireBoulder());

}
