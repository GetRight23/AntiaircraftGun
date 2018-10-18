#ifndef STANDART_AIRPLANE_H
#define STANDART_AIRPLANE_H

#include "EnemyProduct.h"

class StandartAirplane : public EnemyProduct {
public:
	virtual Enemy* getEnemy(AIComponent* ai) override final;
};

#endif