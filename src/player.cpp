//
// Created by warnap on 08.06.2026.
//

#include "player.h"
#include "cmath"

unsigned int Player::getId() const {
    return ID;
}

Player::Player(sf::Vector2f position, unsigned int id) : position(position), ID(id) {
    auto person = std::make_unique<sf::CircleShape>(coefficient/2);
    person->setFillColor(sf::Color::Cyan);
    person->setPosition(StartPos + sf::Vector2f{position.x*coefficient, position.y*coefficient});
    playerContainer.push_back(std::move(person));

    sf::Vector2f centerOfPlayer = sf::Vector2f{StartPos.x + position.x*coefficient + coefficient/2, StartPos.y + position.y*coefficient + coefficient/2};
    for(int i = 0; i < POV + 1; ++i) {
        float sizeOfLine = coefficient/16;

        auto line = std::make_unique<sf::RectangleShape>(sf::Vector2f{VisibilityRange*coefficient, sizeOfLine});

        line->setFillColor(sf::Color::Green);
        line->setPosition(centerOfPlayer - sf::Vector2f{0, sizeOfLine/2});
        line->setOrigin(sf::Vector2f{0, sizeOfLine/2});
        line->setRotation(sf::Angle{this->angle - (sf::degrees(i))});
        playerContainer.push_back(std::move(line));
    }
}


void Player::movePlayer(sf::Vector2f vectorOfVelocity, Map& map) {
    if (vectorOfVelocity.x == 0 && vectorOfVelocity.y == 0)
        return;
    sf::Angle centerOfPOV = this->angle + sf::Angle{sf::degrees(POV/2)};
    vectorOfVelocity = {static_cast<float>(vectorOfVelocity.x * cos(centerOfPOV.asRadians()) - vectorOfVelocity.y * sin(centerOfPOV.asRadians())),
                        static_cast<float>(vectorOfVelocity.x * sin(centerOfPOV.asRadians()) + vectorOfVelocity.y * cos(centerOfPOV.asRadians()))};

    sf::Vector2f newPosX = {position.x + vectorOfVelocity.x, position.y};

    sf::Vector2f newPosY = {position.x, position.y+vectorOfVelocity.y};

    if ((map.getBlock(newPosX)) && (map.getBlock(newPosY))) {
        return;
    } else if (map.getBlock(newPosY)) {
        vectorOfVelocity.y = 0;
    } else if (map.getBlock(newPosX)) {
        vectorOfVelocity.x = 0;
    }
    this->position += vectorOfVelocity;
    for (int i = 0; i < this->playerContainer.size(); ++i) {
        this->playerContainer[i]->move(vectorOfVelocity*coefficient);
    }
}

void Player::draw(sf::RenderWindow &window) {
    unsigned int n = playerContainer.size();
    for (int i = 0; i < n; i++)
        window.draw(*playerContainer[n-1-i]);
}

void Player::rotatePlayer(sf::Angle angle1) {
    if (angle1 == sf::Angle{sf::degrees(0)}) {
        return;
    }
    this->angle += angle1;
    for (int i = 1; i < playerContainer.size(); ++i) {
        this->playerContainer[i]->rotate(angle1);
    }
}