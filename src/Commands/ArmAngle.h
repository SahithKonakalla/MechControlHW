#ifndef ArmAngle_H
#define ArmAngle_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class ArmAngle : public CommandBase {
private:
	double angle;
	double setpoint;

	WVPIDController* anglePID;
public:
	ArmAngle(double pangle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmAngle_H
