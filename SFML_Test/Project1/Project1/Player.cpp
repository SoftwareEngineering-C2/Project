#include "Player.h"

Player::Player()
{
}

sf::Sprite Player::initPlayer(sf::Texture& texture)
{
	texture.loadFromFile("..\\Ressources\\img\\spriteSet.png", sf::IntRect(0, 0, 150, 200));
	sf::Sprite playerSprite(texture);
	playerSprite.setScale(0.4f, 0.4f);
	// Schatten (?)
	//this->playerShadow.setTexture(myTexture);
	//this->playerShadow.setScale(0.4f, 0.4f);
	//this->playerShadow.setColor(sf::Color::Black);
	return playerSprite;
}
void Player::moveLeft()
{
//		this->playerSprite.setPosition(this->playerSprite.getPosition().x - 1, this->playerSprite.getPosition().y);
}

void Player::moveRight()
{
	//	this->playerSprite.setPosition(this->playerSprite.getPosition().x + 1, this->playerSprite.getPosition().y);
}

void Player::moveUp()
{
	//	this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y - 1);
}

void Player::moveDown()
{
	//	this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getPosition().y + 1);
}

float Player::getPosition_x()
{
	//	return this->playerSprite.getPosition().x;
	return 0;
}

float Player::getPosition_y()
{
	//	return this->playerSprite.getPosition().y;
	return 0;
}

float Player::getHeight()
{
	//	return this->playerSprite.getGlobalBounds().height;
	return 0;
}

float Player::getWidth()
{
	//	return this->playerSprite.getGlobalBounds().width;
	return 0;
}

void Player::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}
