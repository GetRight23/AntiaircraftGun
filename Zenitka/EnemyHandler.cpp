#include "EnemyHandler.h"

EnemyHandler::EnemyHandler(void) {
	enemyList.reserve(100);
}
EnemyHandler::~EnemyHandler(void) {
	for (size_t i(0); i < enemyList.size(); ++i)
		delete enemyList[i];
}

void EnemyHandler::addEnemy(Enemy* enemy) {
	enemyList.push_back(enemy);
}

bool EnemyHandler::BulletCollision(Bullet* bullet) {
	for (size_t i(0); i < enemyList.size(); ++i) {
		sf::FloatRect boundingBoxBullet = bullet->getSprite().getGlobalBounds();
		sf::FloatRect boundingBoxAirplane = enemyList[i]->getSprite().getGlobalBounds();
		if (boundingBoxBullet.intersects(boundingBoxAirplane)) {
			enemyList[i]->takeDamage(bullet->getDamage());

			if (enemyList[i]->getHealth() <= 0)
				enemyList[i]->changeLife();

			return true;
		}
	}
	return false;
}

void EnemyHandler::checkDead(void) {
	for (size_t i(0); i < enemyList.size(); ++i)
		if (!enemyList[i]->getLife()) {
			delete enemyList[i];
			enemyList.erase(enemyList.begin() + i);
		}
}

void EnemyHandler::update(float time) {
	for (auto& enemy : enemyList)
		enemy->update(time);
}

bool EnemyHandler::checkWin(void) {
	for (auto& i : enemyList)
		if (i->getX() + i->getW() < 0)
			return true;
	return false;
}