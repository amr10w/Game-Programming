#include "Assets.h"



#include <fstream>
#include <iostream>

Assets::Assets()
{

}

void Assets::addTexture(const std::string& textureName, const std::string& file_path, int posX, int posY, int width, int height, bool smooth)
{
	sf::Texture texture;
	if (!texture.loadFromFile(file_path, sf::IntRect(posX, posY, width, height)))
	{
		std::cerr << "Failed to load texture: " << textureName << " " <<
			file_path << std::endl;
		exit(-1);
	}
	
	texture.setSmooth(smooth);

	m_textureMap[textureName] = texture;
}

void Assets::addAnimation(const std::string& animationName, const std::string& textureName 
	, const size_t frameCount, const size_t duration)
{
	const auto& texture = get_Texture(textureName);
	m_animationMap[animationName] = Animation(animationName, texture, frameCount, duration);

}

void Assets::addFont(const std::string& fontName, const std::string& file_path)
{
	sf::Font font;

	if (!font.loadFromFile(file_path))
	{
		std::cerr << "Failed to load font: " << fontName << " " << file_path <<
			std::endl;
		exit(-1);
	}

	m_fontMap[fontName] = font;


}

const sf::Texture& Assets::get_Texture(const std::string& textureName) const
{
	try {
		return m_textureMap.at(textureName);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Texture not found: " << textureName << std::endl;
		// Optionally, provide a default texture as a fallback
		throw;
	}
}

const Animation& Assets::get_Animation(const std::string& animationName) const
{
	try {
		return m_animationMap.at(animationName);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Texture not found: " << animationName << std::endl;
		// Optionally, provide a default texture as a fallback
		throw;
	}
}

const sf::Font& Assets::get_Font(const std::string& fontName) const
{
	try {
		return m_fontMap.at(fontName);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Texture not found: " << fontName << std::endl;
		// Optionally, provide a default texture as a fallback
		throw;
	}
}

void Assets::loadFromFile(const std::string& filePath)
{
	std::ifstream fin(filePath);
	std::string s;
	
	while (fin >> s)
	{
		if (s == "Texture")
		{
			std::string name, path;
			int x, y, width, height, smooth;
			fin >> name >> path >> x >> y >> width >> height >> smooth;
			addTexture(name, path, x, y, width, height, smooth);

		}
		else if (s == "Animation")
		{
			std::string name, textureName;
			int KeyFrameCount,Speed;
			fin >> name >> textureName >> KeyFrameCount >> Speed;
			addAnimation(name, textureName, KeyFrameCount, Speed);

		}
		else if (s == "Font")
		{
			std::string name, path;
			addFont(name, path);

		}

	}
	
	
}



