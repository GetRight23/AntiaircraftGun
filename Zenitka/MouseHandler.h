#ifndef MOUSE_HANDLER_H
#define MOUSE_HANDLER_H

#include "SFML\Graphics.hpp"
#include "Command.h"
#include "LeftMouseCommand.h"


class MouseHandler {
private:
	Command* leftMouseButton;
public:
	MouseHandler(Command* leftMouseButton);
	Command* handleInput(void);
};

#endif