#include "DriveTrain.h"
#include "../RobotMap.h"
//#include "../Commands/TankDrive.h"
#include "iostream"
using namespace std;
#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)),
							gyro(new ADXRS450_Gyro()) {


	left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// left->ConfigEncoderCodesPerRev(360);
	left->SetSelectedSensorPosition(0,0,10);
	right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// right->ConfigEncoderCodesPerRev(360);
	right->SetSelectedSensorPosition(0,0,10);

	std::cout<<"DriveTrain Constructor Successful" <<std::endl;
	right->SetInverted(true);

	gyro->Calibrate();
	gyro->Reset();



}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());

	//SetDefaultCommand(new TankDrive());
	//std::cout<<"DriveTrain InitDefaultCommand Successful" <<std::endl;
}


void DriveTrain::leftDrive(double leftVal) {
	right->Set(ControlMode::PercentOutput, DriveTrain::Limit(-rightVal, 1.0));
}
void DriveTrain::rightDrive(double rightVal) {
	left->Set(ControlMode::PercentOutput, DriveTrain::Limit(-leftVal, 1.0));
}




// Put methods for controlling this subsystem
// here. Call these from Commands.
