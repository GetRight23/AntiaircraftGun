#ifndef LEFT_MOUSE_COMMAND_H
#define LEFT_MOUSE_COMMAND_H

#include "Command.h"

class LeftMouseCommand : public Command {
public:
	LeftMouseCommand(void);
	virtual void execute(Player& obj, float time) override final;
};

#endif