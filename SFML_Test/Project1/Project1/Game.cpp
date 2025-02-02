#include "Player.h"
#include "Game.h"
#include <iostream>

Game::Game()
{
}

Game::Game(Player* p, sf::Texture &texture)
{
	this->p = p;
	p->initPlayer(texture);
	this->loadSpriteIntoStack("Player", p->getAnimatedSprite());
	this->frameTime = this->frameClock.restart();
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
void Game::updatePlayer(bool keyPressed)
{
	//AnimatedSprite* player = getSpritePtr("Player");
	this->frameTime = this->frameClock.restart();
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		if (stackOfSprites[i].first == "Player")
		{
			if (keyPressed)
				stackOfSprites[i].second->play(*p->getCurrentAnimation(), 0);
			else
			{
				stackOfSprites[i].second->stop();
			}
			stackOfSprites[i].second->setPosition(p->getPosition_x(),p->getPosition_y());
			stackOfSprites[i].second->update(frameTime);
		}
	}
}
