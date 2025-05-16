#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "stateMachine.hpp"
#include "assetManager.hpp"
#include "inputManager.hpp"

namespace Sziad
{
	struct gameData
	{
		stateMachine machine;
		sf::RenderWindow window;
		assetManager assets;
		inputManager input;
	};

	typedef std::shared_ptr<gameData> gameDataRef;

	class game
	{
	public:
		game(unsigned int width, unsigned int height, std::string title);

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;
		gameDataRef _data = std::make_shared<gameData>();

		void run();
	};
}