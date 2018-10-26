#pragma once
#include "SFML/graphics.hpp"
#include "AnimatedSprite.h"

class Player;

class Game
{
private:
	Player* p = nullptr;
	sf::Time gameTime;
	sf::Clock gameClock;
	std::vector < std::pair < std::string, AnimatedSprite* >> stackOfSprites;
	std::vector<std::pair<std::string, AnimatedSprite*>> gameSprites;
public:
	Game();
	Game(Player*, sf::Texture &);
	// Handle Events
	void HandleEvents(sf::RenderWindow& window);

	void loadSpriteIntoStack(std::string, AnimatedSprite*);
	void DrawStackOfSprites(sf::RenderWindow& window);
	AnimatedSprite* getSpritePtr(std::string);
	void updatePlayer();
};
