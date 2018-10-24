#pragma once
#include "SFML/Graphics.hpp"

class Player
{
private:
	float x;
	float y;
public:
	Player();
	sf::Sprite initPlayer(sf::Texture& texture);
	float getPosition_x();
	float getPosition_y();
	float getHeight();
	float getWidth();
	void setPosition(float, float);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};
