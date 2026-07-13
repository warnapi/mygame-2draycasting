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
}


void Player::rotatePlayer(sf::Angle angle1) {
    if (angle1 == sf::Angle{sf::degrees(0)}) {
        return;
    }
    this->angle += angle1;
    this->angle = sf::Angle(sf::degrees(fmod(this->angle.asDegrees(), 360.f)));
    for (int i = 0; i < raysContainer.size(); ++i) {
        this->raysContainer[i]->rotate(angle1);
    }
}

float Player::rayCalculating(Map &map, sf::Vector2f PosOfMapOfRay, sf::Angle angle1) {
    sf::Vector2f unitVectorOfDirection = sf::Vector2f {(float)cos(angle1.asRadians()), (float)sin(angle1.asRadians())};
    sf::Vector2i directionOfMoving;
    sf::Vector2f firstDeltaOfRayToNextBlock;
    sf::Vector2f deltaOfRayToNextBlock;
    if (unitVectorOfDirection.x == 0) deltaOfRayToNextBlock.x = 1e30f;
    else deltaOfRayToNextBlock.x = sqrt(1 + (unitVectorOfDirection.y/unitVectorOfDirection.x)*(unitVectorOfDirection.y/unitVectorOfDirection.x));
    if (unitVectorOfDirection.y == 0) deltaOfRayToNextBlock.y = 1e30f;
    else deltaOfRayToNextBlock.y = sqrt(1 + (unitVectorOfDirection.x/unitVectorOfDirection.y)*(unitVectorOfDirection.x/unitVectorOfDirection.y));


    if (unitVectorOfDirection.x < 0) {
        directionOfMoving.x = -1;
        firstDeltaOfRayToNextBlock.x = (PosOfMapOfRay.x - (int)PosOfMapOfRay.x) * deltaOfRayToNextBlock.x;
    } else {
        directionOfMoving.x = 1;
        firstDeltaOfRayToNextBlock.x = ((int)PosOfMapOfRay.x+1 - PosOfMapOfRay.x) * deltaOfRayToNextBlock.x;
    }
    if (unitVectorOfDirection.y < 0) {
        directionOfMoving.y = -1;
        firstDeltaOfRayToNextBlock.y = (PosOfMapOfRay.y - (int)PosOfMapOfRay.y) * deltaOfRayToNextBlock.y;
    } else {
        directionOfMoving.y = 1;
        firstDeltaOfRayToNextBlock.y = ((int)PosOfMapOfRay.y+1 - PosOfMapOfRay.y) * deltaOfRayToNextBlock.y;
    }

    bool hit = 0;
    float distance = 0.f;
    sf::Vector2i actualPosOnMap = {(int)PosOfMapOfRay.x,(int)PosOfMapOfRay.y};
    while (!hit) {
        if (firstDeltaOfRayToNextBlock.x < firstDeltaOfRayToNextBlock.y) {
            actualPosOnMap.x += directionOfMoving.x;
            distance = firstDeltaOfRayToNextBlock.x;
            firstDeltaOfRayToNextBlock.x += deltaOfRayToNextBlock.x;
        } else {
            actualPosOnMap.y += directionOfMoving.y;
            distance = firstDeltaOfRayToNextBlock.y;
            firstDeltaOfRayToNextBlock.y += deltaOfRayToNextBlock.y;
        }
        if(actualPosOnMap.x < 0 || actualPosOnMap.y < 0 || actualPosOnMap.x > width_of_map-1 || actualPosOnMap.y > height_of_map-1) {
            break;
        }
        if (map.getBlock(actualPosOnMap.x, actualPosOnMap.y)) {
            hit = 1;
        }
        if (distance > VisibilityRange) {
            return VisibilityRange;
        }
    }
    return distance;
}

void Player::calculateRays(Map& map) {
    for (int i = 0; i < raysContainer.size(); ++i) {
        arrOfSizeOfRays[i] = rayCalculating(map, this->position + sf::Vector2f{0.5f,0.5f}, sf::Angle{this->angle - (sf::degrees(i))});
        (*raysContainer[i]).setSize(sf::Vector2f{arrOfSizeOfRays[i]*coefficient,sizeOfLine});
    }
}

const sf::Angle Player::getAngle() const {
    return this->angle;
}

const sf::Vector2f Player::getPosition() const {
    return position;
}

