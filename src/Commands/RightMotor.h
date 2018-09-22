#ifndef RightMotor_H
#define RightMotor_H

#include "../CommandBase.h"

class RightMotor : public CommandBase {
public:
	RightMotor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
