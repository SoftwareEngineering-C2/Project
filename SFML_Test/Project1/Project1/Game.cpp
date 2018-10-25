#include "Player.h"
#include "Game.h"

Game::Game()
{
}

Game::Game(Player* p, sf::Texture &texture)
{
	this->p = p;
	sf::Sprite* playerSprite = p->initPlayer(texture);
	this->loadSpriteIntoStack("Player", playerSprite);
	this->p->setHeight(playerSprite->getGlobalBounds().height);
	this->p->setWidth(playerSprite->getGlobalBounds().width);
}

void Game::loadSpriteIntoStack(std::string name, sf::Sprite *sprite)
{
	std::pair <std::string, sf::Sprite*> pair;
	pair.first = name;
	pair.second = sprite;
	stackOfSprites.push_back(pair);
}

void Game::DrawStackOfSprites(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		window.draw(*stackOfSprites[i].second);
	}
}

sf::Sprite* Game::getSpritePtr(std::string id)
{
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		if (stackOfSprites[i].first == id)
		return stackOfSprites[i].second;
	}
}
void Game::updatePlayer()
{
	sf::Sprite* player = getSpritePtr("Player");
	player->setPosition(this->p->getPosition_x(), this->p->getPosition_y());
}
