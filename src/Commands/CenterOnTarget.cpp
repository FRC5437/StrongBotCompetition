#include "CenterOnTarget.h"
#include "Target.h"

CenterOnTarget::CenterOnTarget()
{

	AddSequential(new Target());
	AddSequential(new Target());
}
