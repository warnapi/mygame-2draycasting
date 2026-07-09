//
// Created by warnap on 08.06.2026.
//

#include "player.h"
#include "game_const.h"

unsigned int Player::getId() const {
    return ID;
}

void Player::setId(unsigned int id) {
    ID = id;
}

Player::Player(sf::Vector2f position, unsigned int id) : position(position), ID(id), angle(0) {}


void Player::movePlayer(sf::Vector2f vectorOfVelocity) {

}

