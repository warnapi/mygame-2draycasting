#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    std::vector<Player> playerStorage; // хранилище объектов
    playerStorage.emplace_back(sf::Vector2f{1,1}, 0);

    std::vector<std::reference_wrapper<Player>> playersRefs;
    for (auto& p : playerStorage) {
        playersRefs.push_back(std::ref(p));
    }
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    Game game = Game(playersRefs, sf::Vector2i {(int)desktop.size.x,(int)desktop.size.y});

    sf::RenderWindow window(sf::VideoMode({desktop.size.x, desktop.size.y}), "mishka");
    sf::Clock clock1;
    sf::Clock fps;
    int fpsCount = 0;
    while (window.isOpen())
    {
        float time = clock1.restart().asSeconds();
        if(fps.getElapsedTime().asSeconds() > 1) {
            printf("fps %d \n", fpsCount);
            fpsCount = 0;
            fps.restart();
        } else {
            fpsCount++;
        }
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        bool event = false;
        sf::Angle angleOfTurn = sf::Angle{sf::degrees(0)};
        sf::Vector2f vectorOfSpeed{0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {vectorOfSpeed.y = -speed; event = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {vectorOfSpeed.x = speed; event = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {vectorOfSpeed.x = -speed; event = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {vectorOfSpeed.y = speed; event = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {angleOfTurn += sf::degrees(speedOfTurn * time); event = true;}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {angleOfTurn -= sf::degrees(speedOfTurn * time); event = true;}
        game.MovePlayer(vectorOfSpeed*time, playersRefs.back().get().getId());
        game.RotatePlayer(angleOfTurn, playersRefs.back().get().getId());
        game.draw(window, event);
    }

    return 0;
}
