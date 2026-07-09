//
// Created by warnap on 12.06.2026.
//

#ifndef PERSON_GAMES_MAP_H
#define PERSON_GAMES_MAP_H


#include "player.h"
#include "game_const.h"

class Map {
private:
    char map_[height_of_map][width_of_map]{};
    Player* player;
public:
    bool getBlock(int i, int j);
    explicit Map(Player *player);
};


#endif //PERSON_GAMES_MAP_H
