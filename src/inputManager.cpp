#include "inputManager.hpp"

namespace Sziad
{
	bool inputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			sf::Vector2f translated_pos = window.mapPixelToCoords(mouse_pos);

			if (object.getGlobalBounds().contains(translated_pos))
			{
				return true;
			}
		}

		return false;
	}

	sf::Vector2i inputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
}