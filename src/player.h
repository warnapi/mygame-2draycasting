//
// Created by warnap on 08.06.2026.
//

#ifndef PLAYER_GAMES_PLAYER_H
#define PLAYER_GAMES_PLAYER_H
#include <SFML/Graphics.hpp>
#include "vector.h"

class Player {
private:
    sf::Vector2f position;
    unsigned int ID;
public:
    Player(sf::Vector2f position, unsigned int id);

    void movePlayer(sf::Vector2f vectorOfVelocity);
    float angle;
    unsigned int getId() const;

    void setId(unsigned int id);
};


#endif

