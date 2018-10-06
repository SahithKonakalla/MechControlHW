#include "Arm.h"
#include "../RobotMap.h"



Arm::Arm() : Subsystem("Arm"), armMotor(new TalonSRX(5)), minPosition(-84),
maxPosition(minPosition + 370) {
	armMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 10);
			// left->ConfigEncoderCodesPerRev(360);
	armMotor->SetSelectedSensorPosition(0,0,10);

	lowLimit = new DigitalInput(1);
	counter = new Counter(lowLimit);

	armMotor->SetInverted(false);
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Arm::move(double power) {
	armMotor-> Set(ControlMode::PercentOutput, Arm::Limit(power, 1));
}

double getPosition() {
	return armMotor->GetSelectedSensorPosition(0);
}

double Arm::getSpeed() {
	return armMotor->GetSelectedSensorVelocity(0);
}

double Limit(double num, double max) {
	if (num > max) {
		return max;
	}

	if (num < -max) {
		return -max;
	}

	return num;
}

double Arm::getMin() {
	return minPosition;
}

double Arm::getMax()
{
	return maxPosition;
}

void Arm::InitializeCounter()
{
     counter->Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
