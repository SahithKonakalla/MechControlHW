#ifndef GroupedDriving_H
#define GroupedDriving_H

#include "LeftMotor.h"
#include "RightMotor.h"

#include <Commands/CommandGroup.h>

class GroupedDriving : public CommandGroup {
public:
	GroupedDriving();
};

#endif  // GroupedDriving_H
