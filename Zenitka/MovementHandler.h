#ifndef MOVEMENT_HANDLER_H
#define MOVEMENT_HANDLER_H

#include "SFML\Graphics.hpp"
#include "Command.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

class MovementHandler {
private:
	Command* buttonLeft;
	Command* buttonRight;
public:
	MovementHandler(Command* buttonLeft, Command* buttonRight);
	Command* handleInput(void);
};

#endif