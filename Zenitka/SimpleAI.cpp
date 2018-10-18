#include "SimpleAI.h"

void AISimple::makeActivity(ActiveObject& obj, float time) {
	static sf::Vector2f direction(LeftDirrection, 0.0f);
	sf::Vector2f copy = direction;

	copy.x *= time * obj.getSpeed();
	copy.y *= time * obj.getSpeed();

	obj.move(copy, time);
}