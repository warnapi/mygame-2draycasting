//
// Created by warnap on 12.06.2026.
//

#ifndef PERSON_GAMES_MAP_H
#define PERSON_GAMES_MAP_H


#include "game_const.h"

class Map{
private:
    char map_[height_of_map][width_of_map]{};
public:
    void drawMap();
    bool getBlock(int x, int y);
    bool getBlock(sf::Vector2f vector, int size);
    explicit Map();
};


#endif //PERSON_GAMES_MAP_H
