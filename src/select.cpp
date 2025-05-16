#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::RenderWindow(sf::VideoMode({ 800, 800 }), "Wizard Game"));
    window.setFramerateLimit(144);

    sf::Font font;
    if (!font.openFromFile("..\\..\\..\\..\\src\\Sprites\\RobotoCondensed-Regular.ttf"))
    {
        std::cerr << "ERROR: COULD NOT LOAD FILE::Sprites/RobotoCondensed-Regular.ttf" << std::endl;
        return -1;
    }

    sf::Text pick_char_text(font);

    pick_char_text.setString("Choose your pet!");
    pick_char_text.setCharacterSize(100);
    pick_char_text.setPosition({ 60.f, 10.f });
    pick_char_text.setFillColor(sf::Color::White);



    // Pet 1

    sf::Texture t_pet1;

    if (!t_pet1.loadFromFile("..\\..\\..\\..\\src\\Sprites\\pet1.png"))
    {
        std::cerr << "ERROR: COULD NOT LOAD FILE::Sprites/pet1.png" << std::endl;
        return -1;
    }

    sf::Sprite s_pet1(t_pet1);

    s_pet1.setPosition({ 40.f, 300.f });
    s_pet1.setScale({ 10.f, 10.f });

    // Pet 1

    // Pet 2

    sf::Texture t_pet2;

    if (!t_pet2.loadFromFile("..\\..\\..\\..\\src\\Sprites\\pet2.png"))
    {
        std::cerr << "ERROR: COULD NOT LOAD FILE::Sprites/pet2.png" << std::endl;
        return -1;
    }

    sf::Sprite s_pet2(t_pet2);

    s_pet2.setPosition({ 280.f, 300.f });
    s_pet2.setScale({ 10.f, 10.f });

    // Pet 2

    // Pet 3

    sf::Texture t_pet3;

    if (!t_pet3.loadFromFile("..\\..\\..\\..\\src\\Sprites\\pet3.png"))
    {
        std::cerr << "ERROR: COULD NOT LOAD FILE::Sprites/pet3.png" << std::endl;
        return -1;
    }

    sf::Sprite s_pet3(t_pet3);

    s_pet3.setPosition({ 520.f, 300.f });
    s_pet3.setScale({ 10.f, 10.f });

    // Pet 3

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2f translated_pos = window.mapPixelToCoords(mouse_pos);

        // Pet 1

        if (s_pet1.getGlobalBounds().contains(translated_pos))
        {
            s_pet1.setOrigin({ 1.f, 1.f });

            s_pet1.setColor(sf::Color::White);
            s_pet1.setScale({ 11.f, 11.f });
        }
        else
        {
            s_pet1.setOrigin({ 0.f, 0.f });
            s_pet1.setColor(sf::Color(220, 220, 220));
            s_pet1.setScale({ 10.f, 10.f });
        }

        // Pet 3

        // Pet 2

        if (s_pet2.getGlobalBounds().contains(translated_pos))
        {
            s_pet2.setOrigin({ 1.f, 1.f });

            s_pet2.setColor(sf::Color::White);
            s_pet2.setScale({ 11.f, 11.f });
        }
        else
        {
            s_pet2.setOrigin({ 0.f, 0.f });
            s_pet2.setColor(sf::Color(220, 220, 220));
            s_pet2.setScale({ 10.f, 10.f });
        }

        // Pet 2

        // Pet 3

        if (s_pet3.getGlobalBounds().contains(translated_pos))
        {
            s_pet3.setOrigin({ 1.f, 1.f });

            s_pet3.setColor(sf::Color::White);
            s_pet3.setScale({ 11.f, 11.f });
        }
        else
        {
            s_pet3.setOrigin({ 0.f, 0.f });
            s_pet3.setColor(sf::Color(220, 220, 220));
            s_pet3.setScale({ 10.f, 10.f });
        }

        // Pet 3

        window.clear();

        window.draw(s_pet1);
        window.draw(s_pet2);
        window.draw(s_pet3);

        window.draw(pick_char_text);

        window.display();
    }
}
