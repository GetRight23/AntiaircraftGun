#ifndef ENEMY_HANDLER_H
#define ENEMY_HANDLER_H

#include "Enemy.h"
#include "Bullet.h"

class EnemyHandler {
private:
	std::vector<Enemy*> enemyList;
public:
	EnemyHandler(void);
	virtual ~EnemyHandler(void);

	void addEnemy(Enemy* enemy);
	bool BulletCollision(Bullet* bullet);
	void checkDead(void);
	bool checkWin(void);
	void update(float time);

	std::vector<Enemy*>& getList(void) { return enemyList; }
};

#endif