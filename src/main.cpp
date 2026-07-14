#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    std::vector<Player> playerStorage; // хранилище объектов
    playerStorage.emplace_back(sf::Vector2f{10,10}, 0);

    std::vector<std::reference_wrapper<Player>> playersRefs;
    for (auto& p : playerStorage) {
        playersRefs.push_back(std::ref(p));
    }

    Game game = Game(playersRefs);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode({desktop.size.x, desktop.size.y}), "mishka");
    sf::Clock clock1;
    while (window.isOpen())
    {
        float time = clock1.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        bool event = 0;
        sf::Angle angleOfTurn = sf::Angle{sf::degrees(0)};
        sf::Vector2f vectorOfSpeed{0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vectorOfSpeed.y = -speed; event = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vectorOfSpeed.x = speed; event = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vectorOfSpeed.x = -speed; event = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vectorOfSpeed.y = speed; event = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) angleOfTurn += sf::degrees(speedOfTurn * time); event = 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) angleOfTurn -= sf::degrees(speedOfTurn * time); event = 1;
        game.MovePlayer(vectorOfSpeed*time, playersRefs.back().get().getId());
        game.RotatePlayer(angleOfTurn, playersRefs.back().get().getId());
        game.draw(window, event);
    }

    return 0;
}
