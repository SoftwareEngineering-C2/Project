#pragma once
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include "Animation.h"

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
private:
	Animation* animation;
	sf::Time stateTime;
	sf::Time currentTime;
	std::size_t currentState;
	bool isPaused;
	bool looped;
	const sf::Texture* texture;
	sf::Vertex vertices[4];

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	explicit AnimatedSprite(sf::Time stateTime = sf::seconds(0.1f), bool paused = false, bool looped = true);

	void update(sf::Time deltaTime);
	void setAnimation(Animation& animation, bool reset);
	void setFrameTime(sf::Time time);
	void play();
	void play(Animation& animation, bool);
	void pause();
	void stop();
	void setLooped(bool looped);
	void setColor(const sf::Color& color);
	const Animation* getAnimation() const;
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;
	bool isLooped() const;
	bool isPlaying() const;
	sf::Time getFrameTime() const;
	void setFrame(std::size_t newFrame, bool resetTime = true);
};