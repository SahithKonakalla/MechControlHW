#ifndef MoveToHeight_H
#define MoveToHeight_H

#include "../CommandBase.h"

class MoveToHeight : public CommandBase {
private:
	double height;
public:
	MoveToHeight(double pheight);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveToHeight_H
