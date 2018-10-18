#ifndef ACTIVE_OBJECT_H
#define ACTIVE_OBJECT_H

#include "Object.h"

class ActiveObject : public Object {
private:
	float speed;
	int health;
public:
	ActiveObject();
	ActiveObject(float x, float y, float sx, float sy, float w, float h, float speed, int health, sf::Texture& texture);
	virtual ~ActiveObject();

	float getSpeed(void) const { return speed; }
	int getHealth(void) const { return health; }

	void setSpeed(float speed) { this->speed = speed; }
	void setHealth(int health) { this->health = health; }

	void  takeDamage(int damage) { health -= damage; }

	void move(sf::Vector2f direction, float time);
};

#endif