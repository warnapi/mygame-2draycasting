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
    this->position = person->getPosition();
    playerContainer.push_back(std::move(person));

}


void Player::movePlayer(sf::Vector2f vectorOfVelocity, Map& map) {
    if (vectorOfVelocity.x == 0 && vectorOfVelocity.y == 0)
        return;
    sf::Vector2f newPos = {position+vectorOfVelocity};
    if (map.getBlock(newPos)) {
        return;
    } else {
        this->position += vectorOfVelocity;
        for (int i = 0; i < this->playerContainer.size(); ++i) {
            this->playerContainer[i]->setPosition(newPos);
        }
    }
}

void Player::draw(sf::RenderWindow &window) {
    for (int i = 0; i < playerContainer.size(); i++)
        window.draw(*playerContainer[i]);
}

