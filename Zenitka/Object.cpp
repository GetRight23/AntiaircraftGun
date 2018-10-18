#include "Object.h"

Object::Object() : x(0), y(0), w(0), h(0), startX(0), startY(0) {
	sprite.setPosition(x, y);
}
Object::Object(float x, float y, float sx, float sy, float w, float h, sf::Texture& texture) : x(x), y(y), w(w), h(h), startX(sx), startY(sy) {
	setTexture(texture);
	sprite.setPosition(x, y);
}

Object::~Object() { }

void Object::setTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(static_cast<int>(startX), static_cast<int>(startY), static_cast<int>(w), static_cast<int>(h)));
	sprite.setOrigin(w / 2.0f, h / 2.0f);
}