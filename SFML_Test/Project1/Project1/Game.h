#pragma once
#include "SFML/graphics.hpp"

class Game
{
private:
	std::vector <sf::Sprite> stackOfSprites;
	std::vector<std::pair<std::string, sf::Sprite>> gameSprites;
public:
	Game();
	// Handle Events
	void HandleEvents(sf::RenderWindow& window);

	void LoadSpriteIntoStack(std::string, sf::Sprite);
	void DrawStackOfSprites(sf::RenderWindow& window);
};
