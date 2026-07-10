#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    Game game = Game({15,15},0);
    sf::RenderWindow window(sf::VideoMode({2560, 1440}), "мишка");
    sf::Clock clock1;
    while (window.isOpen())
    {
        float time = clock1.restart().asSeconds();
        clock1.restart();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Angle angleOfTurn = sf::Angle{sf::degrees(0)};
        sf::Vector2f vectorOfSpeed{0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vectorOfSpeed.y = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vectorOfSpeed.x = speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vectorOfSpeed.x = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vectorOfSpeed.y = speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) angleOfTurn += sf::degrees(speedOfTurn * time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) angleOfTurn -= sf::degrees(speedOfTurn * time);
        game.MovePlayer(vectorOfSpeed*time);
        game.RotatePlayer(angleOfTurn);
        game.draw(window);
    }

    return 0;
}
