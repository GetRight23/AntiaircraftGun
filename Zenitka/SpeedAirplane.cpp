#include "SpeedAirplane.h"

Enemy* SpeedAirplane::getEnemy(AIComponent* ai)  {
	return new Enemy(ScreenWidth + SpeedAirplaneWidth / 2.0f,
		CreationYStart + rand() % (static_cast<int>(CreationYEnd) - static_cast<int>(CreationYStart)), SpeedAirplanePctureX, SpeedAirplanePictureY,
		SpeedAirplaneWidth, SpeedAirplaneHeight, SpeedAirplaneSpeed, SpeedAirplaneHealth, ai, fastAirplane);
}