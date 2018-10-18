#ifndef BULLET_HANDLER_H
#define BULLET_HANDLER_H

#include "Bullet.h"
#include <vector>

class BulletHandler {
private:
	std::vector<Bullet*> bulletList;
public:
	BulletHandler(void);
	~BulletHandler(void);

	void addBulletToList(Bullet* ptr);

	void updateAll(float time);

	auto& getList(void) { return bulletList; }
};

#endif