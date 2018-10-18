#include "LeftMouseCommand.h"

LeftMouseCommand::LeftMouseCommand() {}

void LeftMouseCommand::execute(Player& obj, float time) {
	obj.shooting(time);
}