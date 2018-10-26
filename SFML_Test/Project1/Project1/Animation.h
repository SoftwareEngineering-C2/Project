#pragma once
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>

class Animation
{
private:
	std::vector<sf::IntRect> states;
	sf::Texture* texture;
public:
	Animation();
	void setSheet(sf::Texture&);
	void addState(sf::IntRect);
	const sf::Texture* getSheet() const;
	std::size_t getSize() const;
	const sf::IntRect& getState(std::size_t) const;
};
