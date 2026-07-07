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
    void MovePlayer(Vector vector);
    Game(Vector PositionOfPlayer, unsigned int idOfPlayer);
    void draw(sf::RenderWindow& window, std::vector<std::unique_ptr<sf::Drawable>>& container);
    void init(std::vector<std::unique_ptr<sf::Drawable>>& container);
};


#endif //PERSON_GAMES_GAME_H
