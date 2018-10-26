#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool looped) :
	animation(nullptr), stateTime(frameTime), currentState(0), isPaused(paused), looped(looped), texture(nullptr)
{
	this->looped = looped;
}

void AnimatedSprite::setAnimation(Animation& animation, bool reset)
{
	this->animation = &animation;
	texture = this->animation->getSheet();
	if (reset)
		currentState = 0;
	setFrame(currentState, 0);
}

void AnimatedSprite::setFrameTime(sf::Time time)
{
	stateTime = time;
}

void AnimatedSprite::play()
{
	isPaused = false;
}

void AnimatedSprite::play(Animation& animation, bool reset)
{
	setAnimation(animation, reset);
	play();
}

void AnimatedSprite::pause()
{
	isPaused = true;
}

void AnimatedSprite::stop()
{
	isPaused = true;
	currentState = 0;
	setFrame(currentState, 1);
}

void AnimatedSprite::setLooped(bool looped)
{
	this->looped = looped;
}

void AnimatedSprite::setColor(const sf::Color& color)
{
	// Update the vertices' color
	vertices[0].color = color;
	vertices[1].color = color;
	vertices[2].color = color;
	vertices[3].color = color;
}

const Animation* AnimatedSprite::getAnimation() const
{
	return animation;
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
	sf::IntRect rect = animation->getState(currentState);

	float width = static_cast<float>(std::abs(rect.width));
	float height = static_cast<float>(std::abs(rect.height));

	return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

bool AnimatedSprite::isLooped() const
{
	return looped;
}

bool AnimatedSprite::isPlaying() const
{
	return !isPaused;
}

sf::Time AnimatedSprite::getFrameTime() const
{
	return stateTime;
}

void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime)
{
	if (animation)
	{
		//calculate new vertex positions and texture coordiantes
		sf::IntRect rect = animation->getState(newFrame);

		vertices[0].position = sf::Vector2f(0.f, 0.f);
		vertices[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
		vertices[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
		vertices[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

		float left = static_cast<float>(rect.left) + 0.0001f;
		float right = left + static_cast<float>(rect.width);
		float top = static_cast<float>(rect.top);
		float bottom = top + static_cast<float>(rect.height);

		vertices[0].texCoords = sf::Vector2f(left, top);
		vertices[1].texCoords = sf::Vector2f(left, bottom);
		vertices[2].texCoords = sf::Vector2f(right, bottom);
		vertices[3].texCoords = sf::Vector2f(right, top);
	}

	if (resetTime)
		currentTime = sf::Time::Zero;
}

void AnimatedSprite::update(sf::Time deltaTime)
{
	// if not paused and we have a valid animation
	if (!isPaused && animation)
	{
		// add delta time
		currentTime += deltaTime;

		// if current time is bigger then the frame time advance one frame
		if (currentTime >= stateTime)
		{
			// reset time, but keep the remainder
			currentTime = sf::microseconds(currentTime.asMicroseconds() % stateTime.asMicroseconds());

			// get next Frame index
			if (currentState + 1 < animation->getSize())
				currentState++;
			else
			{
				// animation has ended
				currentState = 0; // reset to start

				if (!looped)
				{
					isPaused = true;
				}

			}

			// set the current frame, not reseting the time
			setFrame(currentState, false);
		}
	}
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (animation && texture)
	{
		states.transform *= getTransform();
		states.texture = texture;
		target.draw(vertices, 4, sf::Quads, states);
	}
}