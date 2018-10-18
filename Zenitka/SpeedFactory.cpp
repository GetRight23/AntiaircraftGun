#include "SpeedFactory.h"

EnemyProduct* SpeedFactory::factoryMethod(void)  {
	return new SpeedAirplane();
}