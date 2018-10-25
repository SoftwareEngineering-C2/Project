#pragma once
#include "Game.h"
#include "SFML/Graphics.hpp"

class Player
{
private:
	float x;
	float y;
	float height;
	float width;
public:
	Player();
	sf::Sprite* initPlayer(sf::Texture& texture);
	float getPosition_x();
	float getPosition_y();
	void setHeight(float);
	void setWidth(float);
	float getHeight();
	float getWidth();
	void setPosition(float, float);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void updatePlayer();
};
