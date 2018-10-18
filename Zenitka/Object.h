#ifndef OBJECT_H
#define OBJECT_H

#include "include\SFML\Graphics.hpp"

class Object {
private:
	float x;
	float y;
	float w;
	float h;
	float startX;
	float startY;
	sf::Sprite sprite;
public:
	Object();
	Object(float x, float y, float sx, float sy, float w, float h, sf::Texture& texture);

	virtual ~Object();

	float getX(void) const { return x; }
	float getY(void) const { return y; }
	float getW(void) const { return w; }
	float getH(void) const { return h; }
	float getSX(void) const { return startX; }
	float getSY(void) const { return startY; }
	sf::Sprite& getSprite(void) { return sprite; }

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setW(float w) { this->w = w; }
	void setH(float h) { this->h = h; }
	void setStartX(float x) { startX = x; }
	void setStartY(float y) { startY = y; }

	void changeX(float x) { this->x += x; }
	void changeY(float y) { this->y += y; }
	void changeW(float w) { this->w += w; }
	void changeH(float h) { this->h += h; }

	void setTexture(sf::Texture& texture);
};

#endif