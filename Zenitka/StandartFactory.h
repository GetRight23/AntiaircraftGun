#ifndef STANDART_FACTORY_H
#define STANDART_FACTORY_H

#include "EnemyFactory.h"
#include "StandartAirplane.h"

class StandartFactory : public EnemyFactory {
public:
	virtual EnemyProduct* factoryMethod(void) override final;
};

#endif