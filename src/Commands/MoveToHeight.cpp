#include "MoveToHeight.h"

MoveToHeight::MoveToHeight(double pheight) {
	height = pheight;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::lift);
}

// Called just before this Command runs the first time
void MoveToHeight::Initialize() {
	lift->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void MoveToHeight::Execute() {
	lift->setPower(0.5); // Not sure what power is good
}

// Make this return true when this Command no longer needs to run execute()
bool MoveToHeight::IsFinished() {
	if (lift->getMotor()->GetSensorCollection.IsFwdLimitSwitchClosed()) {
		// Are limit switches connected directly to the Talon? where do I set a limit switch?
		return true;
	}
	else if (lift->getHeight() > height) {
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void MoveToHeight::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveToHeight::Interrupted() {

}
