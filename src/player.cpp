//
// Created by warnap on 08.06.2026.
//

#include "player.h"
#include "cmath"

unsigned int Player::getId() const {
    return ID;
}

Player::Player(sf::Vector2f position, unsigned int id) : position(position), ID(id) {}


void Player::movePlayer(sf::Vector2f vectorOfVelocity, Map& map) {
    if (vectorOfVelocity.x == 0 && vectorOfVelocity.y == 0)
        return;
    sf::Angle centerOfPOV = sf::Angle{angle + sf::degrees(90 - POV/2)};
    vectorOfVelocity = {static_cast<float>(vectorOfVelocity.x * cos(centerOfPOV.asRadians()) - vectorOfVelocity.y * sin(centerOfPOV.asRadians())),
                        static_cast<float>(vectorOfVelocity.x * sin(centerOfPOV.asRadians()) + vectorOfVelocity.y * cos(centerOfPOV.asRadians()))};

    sf::Vector2f newPosX = {position.x + vectorOfVelocity.x, position.y};

    sf::Vector2f newPosY = {position.x, position.y+vectorOfVelocity.y};

    if ((map.getBlock(newPosX, 1)) && (map.getBlock(newPosY, 1))) {
        return;
    } else if (map.getBlock(newPosY, 1)) {
        vectorOfVelocity.y = 0;
    } else if (map.getBlock(newPosX, 1)) {
        vectorOfVelocity.x = 0;
    }
    this->position += vectorOfVelocity;
}


void Player::rotatePlayer(sf::Angle angle1) {
    if (angle1 == sf::Angle{sf::degrees(0)}) {
        return;
    }
    this->angle += angle1;
    this->angle = sf::Angle(sf::degrees(fmod(this->angle.asDegrees(), 360.f)));
}


sf::Angle Player::getAngle() const {
    return this->angle;
}

sf::Vector2f Player::getPosition() const {
    return position;
}

