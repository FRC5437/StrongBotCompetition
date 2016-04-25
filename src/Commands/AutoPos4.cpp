

#include "AutoPos4.h"

#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"
#include "EngageChassis.h"
#include "HighGear.h"
#include "ResetYaw.h"
#include "RotateDegrees.h"

AutoPos4::AutoPos4() {
	const int defaultDegreesToRotate = 0;
	int degreesToRotate = Preferences::GetInstance()->GetInt("auto4AngleToRotate", defaultDegreesToRotate);
	Robot::logger->log("Updating from preferences auto4AngleToRotate - degreesToRotate: " + std::to_string(degreesToRotate));

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
