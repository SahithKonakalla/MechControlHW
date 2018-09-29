#include "Lift.h"
#include "../RobotMap.h"

Lift::Lift() : Subsystem("Lift"), liftMotor(new TalonSRX(LIFT_MOTOR)) {

	left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	left->SetSelectedSensorPosition(0,0,10);

}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

double Lift::getHeight() {
	return encPosition = liftMotor->GetSensorCollection().GetQuadraturePosition();
	// I have no idea what the calculation between the encoder value and the height is
}

void Lift::setPower(double power) {
	liftMotor->Set(ControlMode::PercentOutput, power);
}

void Lift::resetEncoders() {
	liftMotor->SetSelectedSensorPosition(0,0,10);
}

TalonSRX* Lift::getMotor() {
	return liftMotor;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
