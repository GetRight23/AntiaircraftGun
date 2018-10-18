#include "MouseHandler.h"

MouseHandler::MouseHandler(Command* leftMouseButton) {
	this->leftMouseButton = leftMouseButton;
}

Command* MouseHandler::handleInput(void) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return leftMouseButton;
	return nullptr;
}