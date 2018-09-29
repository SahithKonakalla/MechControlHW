#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "WPILib.h"

class Lift : public Subsystem {
private:
	TalonSRX* liftMotor;

public:
	Lift();
	void InitDefaultCommand();
	void getHeight();
	void resetEncoders();
	void setPower(double power);
	TalonSRX* getMotor();
};

#endif  // Lift_H
