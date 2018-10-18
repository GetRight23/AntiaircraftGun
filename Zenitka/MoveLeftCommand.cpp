#include "MoveLeftCommand.h"

MoveLeftCommand::MoveLeftCommand() {}

void MoveLeftCommand::execute(Player& obj, float time) {
	if(obj.getX() - obj.getW() / QuaterTankWidth > 0)
		obj.moveLeft(time);
}