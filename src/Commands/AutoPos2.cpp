


#include "AutoPos2.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "TurnRight.h"
#include "FireBoulder.h"
#include "RotateDegrees.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "ResetYaw.h"
#include "ResetYaw.h"
#include "HighGear.h"





AutoPos2::AutoPos2() {
	const int defaultDegreesToRotate = 40;
	int degreesToRotate = Preferences::GetInstance()->GetInt("auto2AngleToRotate", defaultDegreesToRotate);
	Robot::logger->log("Updating from preferences auto2AngleToRotate - degreesToRotate: " + std::to_string(degreesToRotate));

	AddParallel(new ResetYaw());
	AddParallel(new PrepShooter());
	AddParallel(new EngageChassis());
	AddSequential(new LowerClimber());
	AddSequential(new WaitCommand(1.0));
	AddSequential(new CrossDefense(2.1));
	AddSequential(new HighGear());
	AddSequential(new CrossDefense(0.8));
	AddSequential(new WaitCommand(0.4));
	AddSequential(new RotateDegrees(degreesToRotate));
	AddSequential(new WaitCommand(0.6));
	AddSequential(new CenterOnTarget());
}
