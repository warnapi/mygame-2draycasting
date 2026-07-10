//
// Created by warnap on 08.06.2026.
//

#include "player.h"

unsigned int Player::getId() const {
    return ID;
}

Player::Player(sf::Vector2f position, unsigned int id) : position(position), ID(id), angle(0) {
    auto person = std::make_unique<sf::CircleShape>(coefficient/2);
    person->setFillColor(sf::Color::Cyan);
    person->setPosition(StartPos + sf::Vector2f{position.x*coefficient, position.y*coefficient});
    playerContainer.push_back(std::move(person));
    sf::Vector2f centerOfPlayer = sf::Vector2f{StartPos.x + position.x*coefficient + coefficient/2, StartPos.y + position.y*coefficient + coefficient/2};
    auto line = std::make_unique<sf::RectangleShape>(sf::Vector2f{VisibilityRange*coefficient, coefficient/8});
    line->setFillColor(sf::Color::Green);
    line->setPosition(centerOfPlayer - sf::Vector2f{0, coefficient/16});
    playerContainer.push_back(std::move(line));
    printf("x = %f,y = %f \n", position.x, position.y);
}


void Player::movePlayer(sf::Vector2f vectorOfVelocity, Map& map) {
    if (vectorOfVelocity.x == 0 && vectorOfVelocity.y == 0)
        return;
    sf::Vector2f newPos = {position+vectorOfVelocity};
    printf("x = %f,y = %f \n", newPos.x, newPos.y);
    if (map.getBlock(newPos) || map.getBlock(newPos.x+1, newPos.y+1)) {
        return;
    } else {
        this->position += vectorOfVelocity;
        for (int i = 0; i < this->playerContainer.size(); ++i) {
            this->playerContainer[i]->move(vectorOfVelocity*coefficient);
        }
    }
}

void Player::draw(sf::RenderWindow &window) {
    unsigned int n = playerContainer.size();
    for (int i = 0; i < n; i++)
        window.draw(*playerContainer[n-1-i]);
}

