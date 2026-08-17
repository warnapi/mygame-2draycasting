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
    window.setMouseCursorVisible(false);
    window.setMouseCursorGrabbed(true);
    sf::Vector2i lastMousePos = sf::Mouse::getPosition(window);
    sf::Clock fps;
    int fpsCount = 0;
    while (window.isOpen())
    {
        float time = clock1.restart().asSeconds();
        if(fps.getElapsedTime().asSeconds() >= 1) {
            fps.restart();
            printf("%d\n", fpsCount);
            fpsCount = 0;
        } else {
            fpsCount++;
        }
        while (const std::optional event1 = window.pollEvent())
        {
            if (event1->is<sf::Event::Closed>())
                window.close();
        }
        sf::Angle angleOfTurn = sf::Angle{sf::degrees((float)(sf::Mouse::getPosition().x - desktop.size.x*0.5) * speedOfTurn)};
        sf::Vector2f vectorOfSpeed{0,0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) vectorOfSpeed.y = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) vectorOfSpeed.x = speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) vectorOfSpeed.x = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) vectorOfSpeed.y = speed;
        game.MovePlayer(vectorOfSpeed*time, playersRefs.back().get().getId());
        game.RotatePlayer(angleOfTurn*time, playersRefs.back().get().getId());
        game.draw(window);
        sf::Mouse::setPosition({(int)desktop.size.x/2,(int)desktop.size.y/2});
    }

    return 0;
}
