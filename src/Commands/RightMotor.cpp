#include "RightMotor.h"

RightMotor::RightMotor() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void RightMotor::Initialize() {
	SetTimeout(5);
}

// Called repeatedly when this Command is scheduled to run
void RightMotor::Execute() {
	drive->rightDrive(0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool RightMotor::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void RightMotor::End() {
	drive->rightDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RightMotor::Interrupted() {

}
