//
// Created by warnap on 13.06.2026.
//

#ifndef PERSON_GAMES_GAME_H
#define PERSON_GAMES_GAME_H

#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"
#include "game_const.h"

class Game {
private:
    Map map;
    Player player;
public:
    void MovePlayer(sf::Vector2f vector);
    Game(sf::Vector2f PositionOfPlayer, unsigned int idOfPlayer);
    void draw(sf::RenderWindow& window);
};


#endif //PERSON_GAMES_GAME_H
