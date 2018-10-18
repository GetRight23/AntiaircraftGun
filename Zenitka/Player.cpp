#include "Player.h"

void Player::moveLeft(float time) {
	if (!isFlipped()) {
		changeFlipp();
		this->setTexture(tankR);
	}
	move(sf::Vector2f(LeftDirrection, 0.0f), time);
}

void Player::moveRight(float time) {
	if (isFlipped()) {
		changeFlipp();
		this->setTexture(tankL);
	}
	move(sf::Vector2f(RightDirrection, 0.0f), time);
}

void Player::shooting(float time) {
	sf::Vector2i position = sf::Mouse::getPosition(*windowPtr);
	sf::Vector2f cursorCoords = windowPtr->mapPixelToCoords(position);

	if (cursorCoords.y < this->getY() - BulletShootingOffset && cursorCoords.y > 0 && 
		cursorCoords.x < ScreenWidth && cursorCoords.x > 0) {
		shoot.play();

		Bullet* bullet = new Bullet(this->getX(), this->getY(), BulletPictureStartX, BulletPictureStartY, BulletPictureWidth,
			BulletPictureHeight, BulletSpeed, cursorCoords.x, cursorCoords.y, BulletDamage);

		bullet->getSprite().setScale(sf::Vector2f(BulletScale, BulletScale));
		bulletHandler.addBulletToList(bullet);
	}
}

Player::Player(float x, float y, float sx, float sy, float w, float h, float speed, int health, sf::RenderWindow* windowPtr)
	: ActiveObject(x, y, sx, sy, w, h, speed, health, tankL), windowPtr(windowPtr) {}
Player::~Player() {}

Player* Player::instatnse = nullptr;