#include "StandartFactory.h"

EnemyProduct* StandartFactory::factoryMethod(void)  {
	return new StandartAirplane();
}