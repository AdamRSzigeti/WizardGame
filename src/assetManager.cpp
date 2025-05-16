#include "assetManager.hpp"

namespace Sziad
{
	void assetManager::loadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &assetManager::getTexture(std::string name)
	{
		return this->_textures.at(name);
	}
	
	void assetManager::loadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.openFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &assetManager::getFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}