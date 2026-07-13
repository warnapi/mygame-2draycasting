//
// Created by warnap on 13.06.2026.
//

#ifndef PERSON_GAMES_GAME_H
#define PERSON_GAMES_GAME_H

#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"
#include "render.h"
#include "game_const.h"

class Game {
private:
    Render render;
    Map map;
    std::vector<std::reference_wrapper<Player>> arrayOfPlayers_;
public:

    void MovePlayer(sf::Vector2f vector);
    void RotatePlayer(sf::Angle angle);
    Game(sf::Vector2f PositionOfPlayer, unsigned int idOfPlayer);
    void draw(sf::RenderWindow& window, bool event);
};


#endif //PERSON_GAMES_GAME_H
