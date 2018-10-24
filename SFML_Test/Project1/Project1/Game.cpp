#include "Game.h"
Game::Game()
{

}

void Game::LoadSpriteIntoStack(std::string name, sf::Sprite sprite)
{
	stackOfSprites.push_back(sprite);
}

void Game::DrawStackOfSprites(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < stackOfSprites.size(); i++)
	{
		window.draw(stackOfSprites[i]);
	}
}