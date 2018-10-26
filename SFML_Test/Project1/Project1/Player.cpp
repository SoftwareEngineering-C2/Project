#include "Player.h"

Player::Player()
{
	this->x = 0;
	this->y = 0;
	this->animatedSprite = new AnimatedSprite(sf::seconds(0.2f), false, true);
}

void Player::initPlayer(sf::Texture& texture)
{
	texture.loadFromFile("..\\Ressources\\img\\playerSpriteSet.png");

	// set up the animations for all four directions (set spritesheet and push frames)
	this->walkingDown.setSheet(texture);
	this->walkingDown.addState(sf::IntRect(32, 0, 32, 32));
	this->walkingDown.addState(sf::IntRect(64, 0, 32, 32));
	this->walkingDown.addState(sf::IntRect(32, 0, 32, 32));
	this->walkingDown.addState(sf::IntRect(0, 0, 32, 32));

	this->walkingLeft.setSheet(texture);
	this->walkingLeft.addState(sf::IntRect(32, 32, 32, 32));
	this->walkingLeft.addState(sf::IntRect(64, 32, 32, 32));
	this->walkingLeft.addState(sf::IntRect(32, 32, 32, 32));
	this->walkingLeft.addState(sf::IntRect(0, 32, 32, 32));

	this->walkingRight.setSheet(texture);
	this->walkingRight.addState(sf::IntRect(32, 64, 32, 32));
	this->walkingRight.addState(sf::IntRect(64, 64, 32, 32));
	this->walkingRight.addState(sf::IntRect(32, 64, 32, 32));
	this->walkingRight.addState(sf::IntRect(0, 64, 32, 32));

	this->walkingUp.setSheet(texture);
	this->walkingUp.addState(sf::IntRect(32, 96, 32, 32));
	this->walkingUp.addState(sf::IntRect(64, 96, 32, 32));
	this->walkingUp.addState(sf::IntRect(32, 96, 32, 32));
	this->walkingUp.addState(sf::IntRect(0, 96, 32, 32));

	this->currentAnimation = &this->walkingDown;
	// set up AnimatedSprite
	this->setWidth(32);
	this->setHeight(32);
	// Schatten (?)
	//this->playerShadow.setTexture(myTexture);
	//this->playerShadow.setScale(0.4f, 0.4f);
	//this->playerShadow.setColor(sf::Color::Black);
	return;
}
void Player::moveLeft()
{
	//this->playerSprite.setPosition(this->playerSprite.getPosition().x - 1, this->playerSprite.getPosition().y);
	this->x -= 1;
}

void Player::moveRight()
{
	//this->playerSprite.setPosition(this->playerSprite.getPosition().x + 1, this->playerSprite.getPosition().y);
	this->x += 1;
}

void Player::moveUp()
{
	//	this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y - 1);
	this->y -= 1;
}

void Player::moveDown()
{
	//	this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y + 1);
	this->y += 1;
}

Animation * Player::getCurrentAnimation()
{
	return this->currentAnimation;
}

AnimatedSprite * Player::getAnimatedSprite()
{
	return this->animatedSprite;
}

void Player::setPlayerAnimation(char id)
{
	switch (id)
	{
	case 'L':
		this->currentAnimation = &this->walkingLeft;
		break;
	case 'R':
		this->currentAnimation = &this->walkingRight;
		break;
	case 'U':
		this->currentAnimation = &this->walkingUp;
		break;
	case 'D':
		this->currentAnimation = &this->walkingDown;
		break;
	default:
		break;
	}
}

float Player::getPosition_x()
{
	//	return this->playerSprite.getPosition().x;
	return this->x;
}

float Player::getPosition_y()
{
	//	return this->playerSprite.getPosition().y;
	return this->y;
}
void Player::setHeight(float h)
{
	this->height = h;
}
void Player::setWidth(float w)
{
	this->width= w;
}
float Player::getHeight()
{
	//	return this->playerSprite.getGlobalBounds().height;
	return this->height;
}

float Player::getWidth()
{
	//	return this->playerSprite.getGlobalBounds().width;
	return this->width;
}

void Player::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}
