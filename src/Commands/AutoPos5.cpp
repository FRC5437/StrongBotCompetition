


#include "AutoPos5.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "RotateDegrees.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "TurnLeft.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"
#include "HighGear.h"



AutoPos5::AutoPos5() {
	const int defaultDegreesToRotate = -30;
	int degreesToRotate = Preferences::GetInstance()->GetInt("auto5AngleToRotate", defaultDegreesToRotate);
	Robot::logger->log("Updating from preferences auto5AngleToRotate - degreesToRotate: " + std::to_string(degreesToRotate));

	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());
	AddSequential(new WaitCommand(1.0));
	AddSequential(new CrossDefense(2.0));
	AddSequential(new HighGear());
	AddSequential(new CrossDefense(0.7));
	AddSequential(new RotateDegrees(degreesToRotate));
	AddSequential(new WaitCommand(0.6));
	AddSequential(new CenterOnTarget());
}
