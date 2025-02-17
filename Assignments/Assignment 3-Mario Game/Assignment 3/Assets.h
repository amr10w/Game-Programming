#pragma once

#include "Animation.h"

#include <map>
#include <SFML/Audio.hpp>

typedef std::map<std::string, sf::Texture>  TextureMap;
typedef std::map<std::string, Animation>  AnimationMap;
typedef std::map<std::string, sf::Font>  FontMap;
typedef std::map < std::string, sf::Sound > SoundMap;

class Assets
{
	TextureMap m_textureMap;
	AnimationMap m_animationMap;
	FontMap m_fontMap;
	//SoundMap m_soundMap;

	void addTexture(const std::string& textureName, const std::string& file_path, int posX, int posY, int width, int height, bool smooth);
	void addAnimation(const std::string& animationName, const std::string& textureName
		, const size_t frameCount, const size_t duration);
	void addFont(const std::string& fontName, const std::string& file_path);
	//void addSound(const std::string& soundName, const std::string& file_path);

public:
	Assets();

	const sf::Texture& get_Texture(const std::string& textureName) const;
	const Animation& get_Animation(const std::string& animationName) const;
	const sf::Font& get_Font(const std::string& fontName) const;
	//const sf::Sound& get_Sound();

	void loadFromFile(const std::string& filePath);

};

