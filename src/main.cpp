#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    Game game = Game({5,5},0);
    sf::RenderWindow window(sf::VideoMode({2560, 1440}), "мишка");
    sf::Clock clock1;
    std::vector<std::unique_ptr<sf::Drawable>> containerOfShapes;
    std::vector<std::unique_ptr<sf::Drawable>> containerOfPlayers;
    game.init(containerOfShapes, containerOfPlayers);
    while (window.isOpen())
    {
        float time = clock1.getElapsedTime().asMicroseconds();
        clock1.restart();
        time /= 800;

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Vector2f vectorOfSpeed(0.f,0.f);
        float speed = 0.3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vectorOfSpeed.y = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vectorOfSpeed.x = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vectorOfSpeed.x = speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vectorOfSpeed.y = speed;
        game.MovePlayer(vectorOfSpeed*time, containerOfPlayers);
        game.draw(window, containerOfShapes, containerOfPlayers);
    }

    return 0;
}
