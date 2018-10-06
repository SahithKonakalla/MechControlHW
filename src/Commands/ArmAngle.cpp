#include "ArmAngle.h"

ArmAngle::ArmAngle(double pangle) : angle(pangle), anglePID(new WVPIDController(0.01, 0, 0, arm->getMax(), false)){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmAngle::Initialize() {
	setpoint = angle - arm->getPosition();
}

// Called repeatedly when this Command is scheduled to run
void ArmAngle::Execute() {
	double power = anglePID->Tick(arm->getPosition());
}

// Make this return true when this Command no longer needs to run execute()
bool ArmAngle::IsFinished()  {
	return arm->getPosition() > setpoint;
}

// Called once after isFinished returns true
void ArmAngle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmAngle::Interrupted() {

}
