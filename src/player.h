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
    std::vector<std::unique_ptr<sf::Shape>> playerContainer;
    sf::Vector2f position;
    unsigned int ID;
    sf::Angle angle;
public:
    Player(sf::Vector2f position, unsigned int id);
    void draw(sf::RenderWindow& window);

    void movePlayer(sf::Vector2f vectorOfVelocity, Map& map);

    void rotatePlayer(sf::Angle angle1);

    unsigned int getId() const;

};


#endif

