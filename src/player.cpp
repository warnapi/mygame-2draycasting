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

Player::Player(Vector position, unsigned int id) : vector({0,0}), position(position),ID(id) {}

