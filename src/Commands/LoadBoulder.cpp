

#include "LoadBoulder.h"


LoadBoulder::LoadBoulder(): Command() {
   Requires(Robot::shooter.get());
	SetTimeout(3);
}

void LoadBoulder::Initialize() {
}

void LoadBoulder::Execute() {
	Robot::shooter->Loadpos();
	Robot::shooter->Load();
	Robot::shooter->Feed();
}

bool LoadBoulder::IsFinished() {
    return IsTimedOut();
}

void LoadBoulder::End() {
	Robot::shooter->Stop();
}

void LoadBoulder::Interrupted() {

}
