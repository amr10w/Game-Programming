#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(const std::string& name, const sf::Texture& texture)
	:Animation(name, texture, 1, 0)
{

}

Animation::Animation(const std::string& name, const sf::Texture& texture,
	size_t keyframesCount, size_t duration)
	: m_name(name)
	, m_sprite(texture)
	, m_keyFrameCount(keyframesCount)
	, m_currentKeyFrame(0)
	, m_speedDuration(duration)
{

}
