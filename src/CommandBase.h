#ifndef CommandBase_H
#define CommandBase_H

#include <memory>
#include <string>
#include <iostream>

#include <Commands/Command.h>

#include "../CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Lift.h"
#include "OI.h"

class CommandBase : public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void initialize();

		// Create a single static instance of all of your subsystems

		static std::unique_ptr<OI> oi;
		static DriveTrain* drive;
		static Lift* lift;
};

#endif  // CommandBase_H
