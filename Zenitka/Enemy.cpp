#include "Enemy.h"

void Enemy::update(float time) {
	if (ai != nullptr)
		ai->makeActivity(*this, time);
}

Enemy::Enemy(float x, float y, float sx, float sy, float w, float h, float speed, int health, AIComponent* ai, sf::Texture& texture)
	: ActiveObject(x, y, sx, sy, w, h, speed, health, texture), ai(ai), life(true) {}