#ifndef SPEED_AIRPLANE_H
#define SPEED_AIRPLANE_H

#include "EnemyProduct.h"
#include "Constants.h"

class SpeedAirplane : public EnemyProduct {
public:
	virtual Enemy* getEnemy(AIComponent* ai) override final;
};

#endif