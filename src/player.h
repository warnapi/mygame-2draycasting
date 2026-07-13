//
// Created by warnap on 08.06.2026.
//

#ifndef PLAYER_GAMES_PLAYER_H
#define PLAYER_GAMES_PLAYER_H
#include <SFML/Graphics.hpp>
#include "map.h"
#include "game_const.h"


class Player {
private:
    sf::Vector2f position;
    unsigned int ID;
    sf::Angle angle;

public:
    const sf::Vector2f getPosition() const;

    const sf::Angle getAngle() const;

    Player(sf::Vector2f position, unsigned int id);

    void movePlayer(sf::Vector2f vectorOfVelocity, Map& map);

    void rotatePlayer(sf::Angle angle1);

    unsigned int getId() const;
};


#endif

