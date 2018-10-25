#include "Player.h"

Player::Player()
{
	this->x = 0;
	this->y = 0;
}

sf::Sprite* Player::initPlayer(sf::Texture& texture)
{
	texture.loadFromFile("..\\Ressources\\img\\spriteSet.png", sf::IntRect(0, 0, 150, 200));
	sf::Sprite* playerSprite = new sf::Sprite();
	playerSprite->setTexture(texture);
	playerSprite->setScale(0.4f, 0.4f);
	// Schatten (?)
	//this->playerShadow.setTexture(myTexture);
	//this->playerShadow.setScale(0.4f, 0.4f);
	//this->playerShadow.setColor(sf::Color::Black);
	return playerSprite;
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
