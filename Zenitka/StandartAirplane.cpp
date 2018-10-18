#include "StandartAirplane.h"

Enemy* StandartAirplane::getEnemy(AIComponent* ai)  {
	return new Enemy(ScreenWidth + StandartAirplaneWidth / 2.0f,
		CreationYStart + rand() % (static_cast<int>(CreationYEnd) - static_cast<int>(CreationYStart)), StandartAirplanePictureX, StandartAirplanePictureY,
		StandartAirplaneWidth, StandartAirplaneHeight, StandrtAirplaneSpeed, StandartAirplaneHealth, ai, standartAirplane);
}