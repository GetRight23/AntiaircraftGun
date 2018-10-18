#ifndef COMMAND_H
#define COMMAND_H

#include "Player.h"

class Command {
public:
	virtual ~Command() {}
	virtual void execute(Player& obj, float time) = 0;
};

#endif