#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "EnemyProduct.h"

class EnemyFactory {
public:
	virtual ~EnemyFactory(void) {}
	virtual EnemyProduct* factoryMethod(void) = 0;
};

#endif