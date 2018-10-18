#ifndef SPEED_FACTORY_H
#define SPEED_FACTORY_H

#include "EnemyFactory.h"
#include "SpeedAirplane.h"

class SpeedFactory : public EnemyFactory {
public:
	virtual EnemyProduct* factoryMethod(void) override final;
};

#endif