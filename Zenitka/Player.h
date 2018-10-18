#ifndef PLAYER_H
#define PLAYER_H

#include "SFML\Graphics.hpp"
#include "ActiveObject.h"
#include "TexturesDefines.h"
#include "Bullet.h"
#include "HandlersDefines.h"
#include "Constants.h"
#include "SoundDefines.h"

class Player : public ActiveObject {
private:
	sf::RenderWindow* windowPtr;

	bool flipped;

	void moveLeft(float time);
	void moveRight(float time);
	void shooting(float time);

	static Player *instatnse;
	Player(float x, float y, float sx, float sy, float w, float h, float speed, int health, sf::RenderWindow* windowPtr);
public:
	~Player();

	friend class MoveLeftCommand;
	friend class MoveRightCommand;
	friend class LeftMouseCommand;

	bool isFlipped(void) const { return flipped; }

	void changeFlipp(void) { flipped = !flipped; }

	static Player& getInstanse(float x, float y, float sx, float sy, float w, float h, float speed, int health, sf::RenderWindow* windowPtr) {
		instatnse = new Player(x, y, sx, sy, w, h, speed, health, windowPtr);
		return *instatnse;
	}

	static Player& get(void) { return *instatnse; }
};

#endif