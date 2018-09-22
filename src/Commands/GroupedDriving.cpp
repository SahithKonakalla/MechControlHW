#include "GroupedDriving.h"


GroupedDriving::GroupedDriving() {

	AddParallel(new LeftMotor());
	AddSequential(new RightMotor());
}
