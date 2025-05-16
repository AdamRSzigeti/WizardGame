#pragma once

#include "state.hpp"
#include "game.hpp"
#include <SFML/Graphics.hpp>  

namespace Sziad  
{  
    class splashState : public state  
    {  
    public:  
        splashState(gameDataRef data);  

        void Init();  

        void HandleInput();  
        void Update(float dt);  
        void Draw(float dt);  

    private:  
        gameDataRef _data;  

        sf::Clock _clock;  

        std::optional<sf::Sprite> _background;
    };  
}