#pragma once

#include "Vec2.h"

#include <SFML/Graphics.hpp>

class Animation
{
	std::string m_name="none";
	size_t      m_keyFrameCount    = 1;
	size_t      m_currentKeyFrame  = 1;
	size_t      m_speedDuration = 1;
	size_t      m_gameFrame        = 1;
	vec2        m_size             = { 1,1 };
	sf::Sprite  m_sprite;

public:
	Animation();
	Animation(const std::string& name, const sf::Texture& texture);
	Animation(const std::string& name, const sf::Texture& texture,
		size_t keyframesCount, size_t duration);

	sf::Sprite& getSprite();
	const std::string& getName()   const;
	const vec2& getSize()   const;

	void update();
	bool hasEnded() const;
};

