

#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoPos1.h"
#include "Commands/AutoPos2.h"
#include "Commands/AutoPos3.h"
#include "Commands/AutoPos4.h"
#include "Commands/AutoPos5.h"
#include "Commands/Climb.h"
#include "Commands/CrossDefense.h"
#include "Commands/DriveRobot.h"
#include "Commands/FireBoulder.h"
#include "Commands/LoadBoulder.h"
#include "Commands/PrepShooter.h"
#include "Commands/PrepToClimb.h"
#include "Commands/RotateDegrees.h"
#include "Commands/Target.h"
#include "Commands/DriveToDistance.h"
#include "Commands/CenterOnTarget.h"
#include "Commands/RotateAbsoluteDegrees.h"
#include "Commands/TransmissionToggle.h"
#include "Commands/ShooterAngleAutonomous.h"
#include "Commands/RaiseClimber.h"
#include "Commands/LowerClimber.h"
#include "Commands/FeedBoulder.h"
#include "Commands/EjectBoulder.h"


#include "Commands/ResetYaw.h"

OI::OI() {
    joy3.reset(new Joystick(2));
    
    b3_3.reset(new JoystickButton(joy3.get(), 3));
    b3_3->WhenPressed(new LoadBoulder());
    b3_6.reset(new JoystickButton(joy3.get(), 6));
    b3_6->WhenPressed(new FeedBoulder());
    b3_7.reset(new JoystickButton(joy3.get(), 7));
    b3_7->WhenPressed(new EjectBoulder());
    b3_2.reset(new JoystickButton(joy3.get(), 2));
    b3_2->WhenPressed(new FireBoulder());
    b3_1.reset(new JoystickButton(joy3.get(), 1));
    b3_1->WhenPressed(new PrepShooter());
    joy2.reset(new Joystick(1));
    
    b2_1.reset(new JoystickButton(joy2.get(), 1));
    b2_4.reset(new JoystickButton(joy2.get(), 5));
    b2_4->WhenPressed(new RaiseClimber());
    b2_7.reset(new JoystickButton(joy2.get(), 7));
    b2_7->WhenPressed(new PrepToClimb());
    b2_8.reset(new JoystickButton(joy2.get(), 8));
    b2_8->WhenPressed(new Climb());
    b2_3.reset(new JoystickButton(joy2.get(), 3));
    b2_3->WhenPressed(new LowerClimber());
    joy1.reset(new Joystick(0));
    
    b1_3.reset(new JoystickButton(joy1.get(), 3));
    b1_3->WhenPressed(new RotateAbsoluteDegrees());

    SmartDashboard::PutNumber("Degrees to rotate", 0);

    // SmartDashboard Buttons
    SmartDashboard::PutData("AutoPos5", new AutoPos5());
    SmartDashboard::PutData("AutoPos4", new AutoPos4());
    SmartDashboard::PutData("AutoPos3", new AutoPos3());
    SmartDashboard::PutData("AutoPos2", new AutoPos2());
    SmartDashboard::PutData("AutoPos1", new AutoPos1());
    SmartDashboard::PutData("Climb", new Climb());
    SmartDashboard::PutData("PrepToClimb", new PrepToClimb());
    SmartDashboard::PutData("RotateDegrees", new RotateDegrees(SmartDashboard::GetNumber("Degrees to rotate", 0)));
    SmartDashboard::PutData("PrepShooter", new PrepShooter());
    SmartDashboard::PutData("LoadBoulder", new LoadBoulder());
    SmartDashboard::PutData("DriveRobot", new DriveRobot());
    SmartDashboard::PutData("FireBoulder", new FireBoulder());
    SmartDashboard::PutData("CrossDefense", new CrossDefense(5));
    SmartDashboard::PutData("Target", new Target());
    SmartDashboard::PutData("Drive To Distance", new DriveToDistance());
    b3_4.reset(new JoystickButton(joy3.get(), 4));
    b3_4->WhenPressed(new Target());

    b3_5.reset(new JoystickButton(joy3.get(), 5));
    b3_5->WhenPressed(new ShooterAngleAutonomous(840));

    SmartDashboard::PutData("Reset Yaw", new ResetYaw());
    SmartDashboard::PutData("Center On Target", new CenterOnTarget());
}


std::shared_ptr<Joystick> OI::getjoy1() {
   return joy1;
}

std::shared_ptr<Joystick> OI::getjoy2() {
   return joy2;
}

std::shared_ptr<Joystick> OI::getjoy3() {
   return joy3;
}

