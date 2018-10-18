#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H

#include "Command.h"

class MoveRightCommand : public Command {
public:
	MoveRightCommand(void);
	virtual void execute(Player& obj, float time) override final;
};

#endif