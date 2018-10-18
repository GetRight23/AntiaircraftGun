#include "ActiveObject.h"
#include <iostream>

ActiveObject::ActiveObject() {}
ActiveObject::~ActiveObject() {}

ActiveObject::ActiveObject(float x, float y, float sx, float sy, float w, float h, float speed, int health, sf::Texture& texture)
	: Object(x, y, sx, sy, w, h, texture), speed(speed), health(health) {}

void ActiveObject::move(sf::Vector2f direction, float time) {
	direction.x *= time * speed;
	direction.y *= time * speed;
	std::cout << direction.x;
	this->changeX(direction.x);
	this->changeY(direction.y);
	this->getSprite().move(direction);
}