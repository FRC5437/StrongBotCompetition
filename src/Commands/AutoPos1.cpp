// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoPos1.h"
#include "../Subsystems/NavX.h"
#include "CrossDefense.h"
#include "Target.h"
#include "PrepShooter.h"
#include "FireBoulder.h"
#include "TurnRight.h"
#include "DriveToDistance.h"
#include "CenterOnTarget.h"
#include "ShooterAngleAutonomous.h"
#include "LowerClimber.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoPos1::AutoPos1() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS

	double duration_seconds = 5.5;
	double rotation_seconds = 1.0;

	AddSequential(new LowerClimber());
	AddParallel(new PrepShooter());

	Robot::logger->log("Executing AutoPos1 CrossDefense duration seconds of : " + std::to_string(duration_seconds));
	AddSequential(new CrossDefense(duration_seconds));

	Robot::logger->log("Executing AutoPos1 TurnRight duration seconds of : " + std::to_string(rotation_seconds));
	AddSequential(new TurnRight(rotation_seconds));

	Robot::logger->log("Executing AutoPos1 CenterOnTarget");
	AddSequential(new CenterOnTarget());

	Robot::logger->log("Executing AutoPos1 ShooterAngleAutonomous");
	AddSequential(new ShooterAngleAutonomous(880));

	Robot::logger->log("Executing AutoPos1 FireBoulder");
	AddSequential(new FireBoulder());

}
