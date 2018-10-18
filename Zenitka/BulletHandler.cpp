#include "BulletHandler.h"

BulletHandler::BulletHandler(void) {}
BulletHandler::~BulletHandler(void) {
	for (size_t i(0); i < bulletList.size(); ++i)
		delete bulletList[i];
}
void BulletHandler::addBulletToList(Bullet* ptr) {
	bulletList.push_back(ptr);
}

void BulletHandler::updateAll(float time) {
	for (auto& bullet : bulletList)
		bullet->update(time);

	for (size_t i(0); i < bulletList.size(); ++i)
		if (bulletList[i]->getX() <= 0 || bulletList[i]->getX() >= ScreenWidth ||
			bulletList[i]->getY() <= 0 || bulletList[i]->getY() >= ScreenHeight) {
			delete bulletList[i];
			bulletList.erase(bulletList.begin() + i);
		}

}