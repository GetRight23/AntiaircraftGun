#ifndef BULLET_H
#define BULLET_H

#include "Object.h"
#include "TexturesDefines.h"
#include "Constants.h"

class Bullet : public Object {
private:
	int damage;
	float speed;
	sf::Vector2f direction;
public:
	Bullet(float x, float y, float sx, float sy, float w, float h, float speed, float toX, float toY, int damage);

	int getDamage(void) const { return damage; }
	void setDamage(int damage) { this->damage = damage; }

	void update(float time);
};

#endif