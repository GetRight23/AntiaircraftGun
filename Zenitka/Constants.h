#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SFML\Graphics.hpp"

//FPS
static const int FPSLismit = 120;

//Transformations
static const float PI = 3.14159265f;
static const float toRadians = 180.0f / PI;

//Window
static const int ScreenWidth = 1280;
static const int ScreenHeight = 720;

//Direction
static const float LeftDirrection = -1.0f;
static const float RightDirrection = 1.0f;

//Bullets
static const int BulletDamage = 1;
static const float ShootingDelay = 0.35f;
static const float BulletPictureStartX = 10.0f;
static const float BulletPictureStartY = 40.0f;
static const float BulletPictureWidth = 115.0f;
static const float BulletPictureHeight = 50.0f;
static const float BulletSpeed = 1.0f;
static const float BulletScale = 0.4f;
static const float BulletShootingOffset = 5.0f;

//Player
static const int TankHealth = 1;
static const float QuaterTankWidth = 4.0f;
static const float TankPictureX = 0.0f;
static const float TankPictureY = 0.0f;
static const float TankPictureWidth = 128.0f;
static const float TankPictureHeight = 128.0f;
static const float TankSpeed = 0.2f;
static const float TankStartX = 50.0f;
static const float TankStartY = 575.0f;
static const float TankScale = 0.5f;

//Cursor
static const float CursorWidth = 256.0f;
static const float CursorHeight = 256.0f;
static const float CursorScale = 0.1f;

//Sounds
static const float ShootingVolume = 5.0f;
static const float TankMovementVolume = 3.0f;
static const float MusicVolume = 20.0f;

//Airplanes
static const int StandartAirplaneHealth = 2;
static const int SpeedAirplaneHealth = 1;
static const float CreationYStart = 50.0f;
static const float CreationYEnd = 250.0f;

static const float SpeedAirplaneSpeed = 0.2f;
static const float StandrtAirplaneSpeed = 0.1f;

static const float StandartAirplanePictureX = 0.0f;
static const float StandartAirplanePictureY = 80.0f;
static const float StandartAirplaneWidth = 256.0f;
static const float StandartAirplaneHeight = 90.0f;
				   
static const float SpeedAirplanePctureX = 25.0f;
static const float SpeedAirplanePictureY = 100.0f;
static const float SpeedAirplaneWidth = 205.0f;
static const float SpeedAirplaneHeight = 55.0f;


//Gameplay
static const float EnemySpawnTime = 5.0f;
static const float LevelTimePlaying = 45.0f;
static const float AirplaneScale = 0.8f;

//Controls
static const sf::Keyboard::Key LeftMovementButton = sf::Keyboard::A;
static const sf::Keyboard::Key RightMovementButton = sf::Keyboard::D;


//Text
static const float ScorePositionX = 10.0f;
static const float ScorePositionY = 680.0f;
static const int FontSize = 20;

//Menu
static const int startGameX = 450;
static const int startGameY = 200;
static const int startGameW = 300;
static const int startgameH = 63;

static const int endGameX = 450;
static const int endGameY = 300;
static const int endGameW = 300;
static const int endgameH = 63;

static const int MsecForFrame = 16;
#endif