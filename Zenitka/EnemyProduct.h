#ifndef ENEMY_PRODUCT_H
#define ENEMY_PRODUCT_H

#include "Enemy.h"
#include "Constants.h"

class EnemyProduct {
public:
	virtual Enemy* getEnemy(AIComponent*) = 0;
	virtual ~EnemyProduct(void) {}
};

#endif