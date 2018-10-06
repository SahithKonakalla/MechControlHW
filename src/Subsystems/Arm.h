#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include <WPILib.h>
#include "math.h"

class Arm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* armMotor;
	double maxPosition;
	double minPosition;

	DigitalInput* lowLimit;
	Counter* counter;

public:
	Arm();
	void InitDefaultCommand();
	Arm();
		void InitDefaultCommand();
		void move(double power);
		void reset();
		double getPosition();
		double getSpeed();
		double Limit(double num, double max);
		//Encoder* getEncoder();
		TalonSRX* getArmMotor();
		double getMin();
		double getMax();

		bool IsSwitchSet();
		void InitializeCounter();
};

#endif  // Arm_H
