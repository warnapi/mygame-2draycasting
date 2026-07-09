//
// Created by warnap on 13.06.2026.
//
#include "game.h"


Game::Game(sf::Vector2f PositionOfPlayer, unsigned int idOfPlayer) : player(Player{PositionOfPlayer, idOfPlayer}), map(Map{&(this->player)}) {}


void Game::MovePlayer(sf::Vector2f vector, std::vector<std::unique_ptr<sf::Drawable>>& playerContainer) {
    this->player.position += vector;
    playerContainer.begin()->sf::setPo
}

void Game::draw(sf::RenderWindow& window, std::vector<std::unique_ptr<sf::Drawable>>& mapContainer, std::vector<std::unique_ptr<sf::Drawable>>& playerContainer) {
    window.clear();
    for (int i = 0; i < mapContainer.size(); i++)
        window.draw(*mapContainer[i]);
    for (int i = 0; i < playerContainer.size(); ++i) {
        window.draw(*playerContainer[i]);
    }
    window.display();
}

void Game::init(std::vector<std::unique_ptr<sf::Drawable>>& mapContainer, std::vector<std::unique_ptr<sf::Drawable>>& playerContainer) {
    float coefficient = 30;
    float thicknessOfBoarders = 5;
    auto mapOnScreen = std::make_unique<sf::RectangleShape>(sf::Vector2f {width_of_map*coefficient, height_of_map*coefficient});
    sf::Vector2f startPos({900, 400});
    mapOnScreen->setPosition(startPos);
    mapOnScreen->setFillColor(sf::Color::Blue);
    mapContainer.push_back(std::move(mapOnScreen));                       //map back init
    for (int i = 0; i < height_of_map; ++i) {
        for (int j = 0; j < width_of_map; ++j) {
            if(this->map.getBlock(i,j)) {
                auto block  = std::make_unique<sf::RectangleShape>(sf::Vector2f{coefficient-2*thicknessOfBoarders,coefficient-2*thicknessOfBoarders});
                block->setPosition(startPos + sf::Vector2f{(float)j*coefficient + thicknessOfBoarders,(float)i*coefficient + thicknessOfBoarders});
                block->setFillColor(sf::Color::Red);
                block->setOutlineThickness(thicknessOfBoarders);
                block->setOutlineColor(sf::Color::White);
                mapContainer.push_back(std::move(block));
            }
        }
    }
    auto person = std::make_unique<sf::CircleShape>(coefficient/2);
    person->setFillColor(sf::Color::Cyan);
    person->setPosition(startPos + sf::Vector2f{(width_of_map/2)*coefficient, (height_of_map/2)*coefficient});
    this->player.position = person->getPosition();
    playerContainer.push_back(std::move(person));
}