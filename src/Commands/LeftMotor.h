#ifndef LeftMotor_H
#define LeftMotor_H

#include "../CommandBase.h"

class LeftMotor : public CommandBase {
public:
	LeftMotor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
