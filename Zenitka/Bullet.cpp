#include "Bullet.h"

void Bullet::update(float time) {
	sf::Vector2f copy = direction;
	copy.x *= time * speed;
	copy.y *= time * speed;

	this->changeX(copy.x);
	this->changeY(copy.y);

	this->getSprite().move(copy);
}

Bullet::Bullet(float x, float y, float sx, float sy, float w, float h, float speed, float toX, float toY, int damage)
	: Object(x, y, sx, sy, w, h, bullet), speed(speed), damage(damage) {
	direction.x = toX - x;
	direction.y = toY - y;

	float rotation = atan2(direction.y, direction.x) * toRadians;

	this->getSprite().rotate(rotation);

	float length = sqrt(powf(direction.x, 2) + powf(direction.y, 2));

	direction.x /= length;
	direction.y /= length;
}