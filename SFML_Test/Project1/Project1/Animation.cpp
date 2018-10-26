#include "Animation.h"

Animation::Animation()
{
}

void Animation::setSheet(sf::Texture &texture)
{
	this->texture = &texture;
}

void Animation::addState(sf::IntRect rect)
{
	states.push_back(rect);
}

const sf::Texture * Animation::getSheet() const
{
	return this->texture;
}

std::size_t Animation::getSize() const
{
	return this->states.size();
}

const sf::IntRect &Animation::getState(std::size_t i) const
{
	return this->states[i];
}
