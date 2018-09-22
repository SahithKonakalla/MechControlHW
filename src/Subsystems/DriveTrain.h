#ifndef DriveTrain_H
#define DriveTrain_H

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "math.h"

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem {
private:
	TalonSRX* left;
	TalonSRX* right;
	ADXRS450_Gyro* gyro;
	double circumference = 6 * M_PI; //diameter = 6 inches

public:
	DriveTrain();
	void InitDefaultCommand();
	void leftDrive(double leftVal);
	void rightDrive(double rightVal);
};

#endif  // DriveTrain_H
