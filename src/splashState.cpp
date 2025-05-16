#include <sstream>
#include "splashState.hpp"

#include <iostream>
#include "DEFINITIONS.hpp"

namespace Sziad
{
	splashState::splashState(gameDataRef data) : _data(data)
	{

	}
		
	void splashState::Init()
	{
		this->_data->assets.loadTexture("splashStateBackground", SPLASH_SCENE_BACKGROUND_FILEPATH);

		const sf::Texture& texture = this->_data->assets.getTexture("splashStateBackground");

		_background.emplace(texture);

		
	}

	void splashState::HandleInput()
	{
		while (auto event = this->_data->window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				this->_data->window.close();
			}
		}


	}

	void splashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch to the char select
			std::cout << "Go to char select" << std::endl;
		}
	}

	void splashState::Draw(float dt)
	{
		this->_data->window.clear();

		if (_background)
		{
			this->_data->window.draw(*_background);
		}

		this->_data->window.display();
	}
}