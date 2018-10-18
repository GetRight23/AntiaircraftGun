#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H

#include "Command.h"

class MoveLeftCommand : public Command {
public:
	MoveLeftCommand(void);
	virtual void execute(Player& obj, float time);
};

#endif