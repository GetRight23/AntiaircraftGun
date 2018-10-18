#include "MovementHandler.h"

MovementHandler::MovementHandler(Command* buttonLeft, Command* buttonRight) {
	this->buttonLeft = buttonLeft;
	this->buttonRight = buttonRight;
}

Command* MovementHandler::handleInput(void) {
	if (sf::Keyboard::isKeyPressed(LeftMovementButton))
		return buttonLeft;
	if (sf::Keyboard::isKeyPressed(RightMovementButton))
		return buttonRight;

	return nullptr;
}