//
// Created by warnap on 12.06.2026.
//

#include <cstdio>
#include <cstdlib>
#include "map.h"

Map::Map(Player *player){
    this->player = player;
    for (int i = 0; i < height_of_map; i++) {
        for (int j = 0; j < width_of_map; ++j) {
            if(i == 0 || j == 0 || i == height_of_map-1 || j == width_of_map-1) {
                map_[i][j] = '#';
            } else {
                map_[i][j] = ' ';
            }
        }
    }
}

bool Map::getBlock(int i, int j) {
    if (this->map_[i][j] == '#')
        return true;
    else
        return false;
}

