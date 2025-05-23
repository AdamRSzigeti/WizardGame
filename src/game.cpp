#include "game.hpp"
#include "splashState.hpp"

namespace Sziad
{
	game::game(unsigned int width, unsigned int height, std::string title)
		: _data(std::make_shared<gameData>())
	{
		_data->window.create(sf::VideoMode({ width, height }), title, sf::Style::Close | sf::Style::Titlebar);

		_data->machine.addState(stateRef(new splashState(_data)));

		this->run();
	}


	void game::run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.getActiveState()->HandleInput();
				this->_data->machine.getActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->Draw(dt);
		}
	}
}