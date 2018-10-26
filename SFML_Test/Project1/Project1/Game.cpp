#include "Player.h"
#include "Game.h"

Game::Game()
{
}

Game::Game(Player* p, sf::Texture &texture)
{
	this->p = p;
	p->initPlayer(texture);
	this->loadSpriteIntoStack("Player", p->getAnimatedSprite());
}

void Game::loadSpriteIntoStack(std::string name, AnimatedSprite* sprite)
{
	std::pair <std::string, AnimatedSprite*> pair;
	pair.first = name;
	pair.second = sprite;
	if (stackOfSprites.empty())
	{
		stackOfSprites.push_back(pair);
		return;
	}
	for (int i = 0; i < stackOfSprites.size(); i++)
	{
		if (stackOfSprites[i].first == "Player")
		{
			stackOfSprites[i].second = pair.second;
			return;
		}
	}
}

void Game::DrawStackOfSprites(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		AnimatedSprite* sprite = stackOfSprites[i].second;
		window.draw(*sprite);
	}
}

AnimatedSprite* Game::getSpritePtr(std::string id)
{
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		if (stackOfSprites[i].first == id)
			return stackOfSprites[i].second;
	}
}
void Game::updatePlayer()
{
	//AnimatedSprite* player = getSpritePtr("Player");
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		if (stackOfSprites[i].first == "Player")
		{
			stackOfSprites[i].second->play(*p->getCurrentAnimation());
			stackOfSprites[i].second->setPosition(sf::Vector2f(p->getPosition_x(), p->getPosition_y()));
			stackOfSprites[i].second->update(sf::seconds(0.2));

		}
	}
}
