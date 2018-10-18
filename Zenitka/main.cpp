#include "Constants.h"
#include "TexturesDefines.h"
#include "Object.h"
#include "MovementHandler.h"
#include "MouseHandler.h"
#include "Bullet.h"
#include "BulletHandler.h"
#include "SoundDefines.h"
#include "SpeedFactory.h"
#include "StandartFactory.h"
#include "SimpleAI.h"
#include <string>
#include <thread>
#include <windows.h>
#include <atomic>
#include <mutex>

sf::Image tankImageL;
sf::Texture tankL;
sf::Texture tankR;
sf::Texture backGround;
sf::Texture bullet;
sf::Texture cursor;
sf::Texture standartAirplane;
sf::Texture fastAirplane;

sf::SoundBuffer shootBuffer;
sf::SoundBuffer tankBuffer;
sf::Music backGroundMusic;
sf::Sound shoot;
sf::Sound tankSound;

BulletHandler bulletHandler;
EnemyHandler enemyHandler;

std::atomic<bool> exitMusicThread = false;

bool TextureInitialization(void) {
	if (!tankImageL.loadFromFile("data\\pictures\\tank.png"))
		return false;
	tankL.loadFromImage(tankImageL);

	sf::Image tankImageR;
	if (!tankImageR.loadFromFile("data\\pictures\\tank.png"))
		return false;

	tankImageR.flipHorizontally();
	tankR.loadFromImage(tankImageR);

	sf::Image airplaneImage;
	if (!airplaneImage.loadFromFile("data\\pictures\\ac130.png"))
		return false;
	airplaneImage.flipHorizontally();
	standartAirplane.loadFromImage(airplaneImage);

	if (!fastAirplane.loadFromFile("data\\pictures\\fastAirplane.png"))
		return false;

	if (!backGround.loadFromFile("data\\pictures\\background.jpg"))
		return false;

	if (!bullet.loadFromFile("data\\pictures\\bullet.png"))
		return false;

	if (!cursor.loadFromFile("data\\pictures\\cursor.png"))
		return false;

	return true;
}

bool SoundsInitialization(void) {
	if (!shootBuffer.loadFromFile("data\\sounds\\shooting.wav"))
		return false;
	shoot.setBuffer(shootBuffer);
	shoot.setVolume(ShootingVolume);

	if (!tankBuffer.loadFromFile("data\\sounds\\tank.flac"))
		return false;
	tankSound.setBuffer(tankBuffer);
	tankSound.setVolume(TankMovementVolume);

	return true;
}

void MusicThread(void) {
	std::vector<std::string> musicList{ "data\\music\\memories.ogg" };
	while (!exitMusicThread) {
		if (backGroundMusic.getStatus() != backGroundMusic.Playing) {
			int song = rand() % musicList.size();

			backGroundMusic.openFromFile(musicList[song]);
			backGroundMusic.setVolume(MusicVolume);
			backGroundMusic.play();
		}
		Sleep(100);
	}
	backGroundMusic.stop();
}

int gameMenu(sf::RenderWindow & window) {
	sf::Texture menuTextureStartGame, menuTextureEndGame;
	menuTextureStartGame.loadFromFile("data\\pictures\\startGame.png");
	menuTextureEndGame.loadFromFile("data\\pictures\\endGame.png");

	sf::Sprite firstOption(menuTextureStartGame), secondOption(menuTextureEndGame), backGround(::backGround);
	bool menuOpen = true;
	int menuNumber;
	
	firstOption.setPosition(startGameX, startGameY);
	secondOption.setPosition(endGameX, endGameY);
	window.setMouseCursorVisible(true);

	sf::Event event;
	while (menuOpen && window.isOpen()) {
		menuNumber = 0;
		firstOption.setColor(sf::Color::Red);
		secondOption.setColor(sf::Color::Red);

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::IntRect(startGameX, startGameY, endGameW, endgameH).contains(sf::Mouse::getPosition(window))) {
			firstOption.setColor(sf::Color::Blue);
			menuNumber = 1;
		}

		if (sf::IntRect(endGameX, endGameY, endGameW, endgameH).contains(sf::Mouse::getPosition(window))) {
			secondOption.setColor(sf::Color::Blue);
			menuNumber = 2;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && menuNumber != 0) {
			window.setMouseCursorVisible(false);
			return menuNumber;
		}

		window.draw(backGround);
		window.draw(firstOption);
		window.draw(secondOption);

		window.display();
	}

	window.setMouseCursorVisible(false);
	return 0;
}

int main(int argc, char* argv[]) {
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Game", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FPSLismit);
	window.setMouseCursorVisible(false);
	
	srand(static_cast<unsigned int>(time(NULL)));

	if (!TextureInitialization())
		return EXIT_FAILURE;

	if(!SoundsInitialization())
		return EXIT_FAILURE;

	window.setIcon(static_cast<unsigned int>(TankPictureWidth), static_cast<unsigned int>(TankPictureWidth), tankImageL.getPixelsPtr());

	std::thread musicThread(MusicThread);

	sf::Font font;
	font.loadFromFile("data\\ttf\\tahomabd.ttf");

	sf::Text score("Hello", font, FontSize);
	score.setPosition(sf::Vector2f(ScorePositionX, ScorePositionY));

	sf::Sprite cursorSprite;
	cursorSprite.setTexture(cursor);
	cursorSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(CursorWidth), static_cast<int>(CursorHeight)));
	cursorSprite.setOrigin(CursorWidth / 2, CursorHeight / 2);
	cursorSprite.scale(CursorScale, CursorScale);

	Object backGroundImage(0.0f, 0.0f, 0.0f, 0.0f, static_cast<float>(ScreenWidth), static_cast<float>(ScreenHeight), backGround);
	backGroundImage.getSprite().setOrigin(0, 0);

	Player& tank = Player::getInstanse(TankStartX, TankStartY, TankPictureX, TankPictureY, TankPictureWidth, TankPictureHeight, TankSpeed, TankHealth, &window);
	tank.getSprite().scale(sf::Vector2f(TankScale, TankScale));

	Command* leftMovement = new MoveLeftCommand();
	Command* rightMovement = new MoveRightCommand();
	MovementHandler keyboardHandler(leftMovement, rightMovement);

	Command* shooting = new LeftMouseCommand();
	MouseHandler mouseHandler(shooting);

	const size_t factoryiesCount = 2;
	SpeedFactory speedFactory;
	StandartFactory standartFactory;
	EnemyFactory* factoryies[factoryiesCount] = { &speedFactory, &standartFactory };

	const size_t aiCount = 1;
	AISimple aiSimple;
	AIComponent* aiLevels[aiCount] = { &aiSimple };

	int level = 1, points = 0;

	int startTime, endTime;
	float gameTime, shootTime, enemyTime, levelTime;
	sf::Clock timer, shootTimer, enemyTimer, levelTimer, drawTimer;

	bool isMenu = true;
	sf::Vector2i absoluteCursorPosition;
	sf::Vector2f windowCursorPosition;

	sf::Event event;
	int choose = 0;
	do {
		if (isMenu) {
			choose = gameMenu(window);
			if (choose == 1) {
				isMenu = false;

				timer.restart();
				shootTimer.restart();
				enemyTimer.restart();
				levelTimer.restart();
				drawTimer.restart();

				Sleep(50);
				continue;
			}
			else if (choose == 2)
				break;
		}

		if(choose == 1) {

			drawTimer.restart();
			startTime = drawTimer.getElapsedTime().asMilliseconds();
			gameTime = static_cast<float>(timer.getElapsedTime().asMilliseconds());
			timer.restart();
			enemyTime = enemyTimer.getElapsedTime().asSeconds();
			levelTime = levelTimer.getElapsedTime().asSeconds();

			if (levelTime > LevelTimePlaying) {
				levelTimer.restart();
				++level;
			}

			score.setString(std::string("Score: " + std::to_string(points)));

			if (enemyTime > EnemySpawnTime / level) {
				enemyTimer.restart();
				EnemyProduct* product = factoryies[rand() % factoryiesCount]->factoryMethod();
				Enemy* createdEnemy = product->getEnemy(aiLevels[rand() % aiCount]);
				createdEnemy->getSprite().setScale(AirplaneScale, AirplaneScale);
				enemyHandler.addEnemy(createdEnemy);
			}

			bool callMenu = false;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					shoot.setVolume(0);
				}
				if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(LeftMovementButton) || sf::Keyboard::isKeyPressed(RightMovementButton))
					if (tankSound.getStatus() != tankSound.Playing)
						tankSound.play();

				if (event.type == sf::Event::KeyReleased && !(sf::Keyboard::isKeyPressed(LeftMovementButton) || sf::Keyboard::isKeyPressed(RightMovementButton)))
					tankSound.stop();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					isMenu = true;
					callMenu = true;
					level = 1;
					points = 0;
					choose = -1;
				}
			}

			if (callMenu == true)
				continue;

			Command* keyboardCommand = keyboardHandler.handleInput();
			if (keyboardCommand != nullptr)
				keyboardCommand->execute(tank, gameTime);

			Command* mouseCommand = mouseHandler.handleInput();
			if (mouseCommand != nullptr) {
				shootTime = shootTimer.getElapsedTime().asSeconds();
				if (shootTime > ShootingDelay) {
					shootTimer.restart();
					mouseCommand->execute(tank, gameTime);
				}
			}

			absoluteCursorPosition = sf::Mouse::getPosition(window);
			windowCursorPosition = window.mapPixelToCoords(absoluteCursorPosition);
			cursorSprite.setPosition(windowCursorPosition);

			bulletHandler.updateAll(gameTime);

			enemyHandler.update(gameTime);

			for (size_t i(0); i < bulletHandler.getList().size(); ++i) {
				if (enemyHandler.BulletCollision(bulletHandler.getList()[i])) {
					delete bulletHandler.getList()[i];
					++points;
					bulletHandler.getList().erase(bulletHandler.getList().begin() + i);
				}
			}

			enemyHandler.checkDead();

			if (enemyHandler.checkWin())
				window.close();

			window.clear();
			window.draw(backGroundImage.getSprite());

			for (auto& i : bulletHandler.getList())
				window.draw(i->getSprite());

			window.draw(tank.getSprite());

			for (auto& i : enemyHandler.getList())
				window.draw(i->getSprite());

			window.draw(score);
			window.draw(cursorSprite);
			window.display();

			endTime = drawTimer.getElapsedTime().asMilliseconds();
			int elapsedTime = startTime + MsecForFrame - endTime;

			if (elapsedTime > 0)
				Sleep(elapsedTime);
		}

	} while (window.isOpen() && choose != 0);
	exitMusicThread = true;
	musicThread.join();

	delete leftMovement;
	delete rightMovement;
	delete shooting;

	return EXIT_SUCCESS;
}