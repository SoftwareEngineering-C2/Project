#pragma once
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "AnimatedSprite.h"

class Player
{
private:
	float x;
	float y;
	float height;
	float width;
	Animation walkingDown;
	Animation walkingUp;
	Animation walkingLeft;
	Animation walkingRight;
	Animation* currentAnimation;
	AnimatedSprite* animatedSprite;
public:
	Player();
	void initPlayer(sf::Texture& texture);
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
	Animation* getCurrentAnimation();
	AnimatedSprite* getAnimatedSprite();
	void setPlayerAnimation(char);
};
