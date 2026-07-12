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
    std::vector<std::unique_ptr<sf::RectangleShape>> raysContainer;
    std::unique_ptr<sf::CircleShape> ballOfPlayerOnMap;
    sf::Vector2f position;
    unsigned int ID;
    sf::Angle angle;
    std::vector<float> arrOfSizeOfRays;
public:
    Player(sf::Vector2f position, unsigned int id);
    void draw(sf::RenderWindow& window, Map& map);

    void movePlayer(sf::Vector2f vectorOfVelocity, Map& map);

    void rotatePlayer(sf::Angle angle1);

    unsigned int getId() const;

    float rayCalculating(Map& map, sf::Vector2f startPosOfRay, sf::Angle angle1);

    void calculateRays(Map& map);
};


#endif

