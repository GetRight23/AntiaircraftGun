#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand() {}

void MoveRightCommand::execute(Player& obj, float time) {
	if (obj.getX() + obj.getW() / QuaterTankWidth < ScreenWidth)
		obj.moveRight(time);
}