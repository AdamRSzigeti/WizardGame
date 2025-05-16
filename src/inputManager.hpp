#pragma once

#include <SFML/Graphics.hpp>

namespace Sziad
{
	class inputManager
	{
	public:
		inputManager() {}
		~inputManager() {}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}