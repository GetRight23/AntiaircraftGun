#ifndef ENEMY_H
#define ENEMY_H

#include "ActiveObject.h"
#include "AIComponent.h"
#include "TexturesDefines.h"

class Enemy : public ActiveObject {
private:
	AIComponent* ai = nullptr;
	bool life;
public:
	Enemy(float x, float y, float sx, float sy, float w, float h, float speed, int health, AIComponent* ai, sf::Texture& texture);

	void changeLife(void) { life = !life; }
	bool getLife(void) const { return life; }

	void update(float time);
};

#endif