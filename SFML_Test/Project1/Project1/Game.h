#pragma once
#include "SFML/graphics.hpp"

class Player;

class Game
{
private:
	Player* p = nullptr;
	std::vector < std::pair < std::string, sf::Sprite* >> stackOfSprites;
	std::vector<std::pair<std::string, sf::Sprite*>> gameSprites;
public:
	Game();
	Game(Player*, sf::Texture &);
	// Handle Events
	void HandleEvents(sf::RenderWindow& window);

	void loadSpriteIntoStack(std::string, sf::Sprite*);
	void DrawStackOfSprites(sf::RenderWindow& window);
	sf::Sprite *getSpritePtr(std::string);
	void updatePlayer();
};
