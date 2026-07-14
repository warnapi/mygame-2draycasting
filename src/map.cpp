//
// Created by warnap on 12.06.2026.
//

#include "map.h"

Map::Map() {
    for (int i = 0; i < height_of_map; i++) {
        for (int j = 0; j < width_of_map; ++j) {
            if(i == 0 || j == 0 || i == height_of_map-1 || j == width_of_map-1 || (j == 10 && i < 10)) {
                map_[i][j] = '#';
            } else {
                map_[i][j] = ' ';
            }
        }
    }
}

bool Map::getBlock(int x, int y) {
    if (x < 0 || y < 0 || x >= width_of_map || y >= height_of_map || map_[y][x] == '#')
    {return true;}
    else
    {return false;}
}

bool Map::getBlock(sf::Vector2f vector, int size) {
    if ((int)(vector.x) < 0 || (int)(vector.y) < 0 || (int)(vector.x) >= width_of_map || (int)(vector.y) >= height_of_map || this->map_[(int)(vector.y)][(int)vector.x] == '#'
    || this->map_[(int)(vector.y+size)][(int)vector.x] == '#'  || this->map_[(int)(vector.y)][(int)vector.x+size] == '#'  || this->map_[(int)(vector.y+size)][(int)vector.x+size] == '#') {
        return true;
    }
    else{
        return false;
    }
}

void Map::drawMap() {
    for (int i = 0; i < height_of_map; i++) {
        for (int j = 0; j < width_of_map; ++j) {
            printf("%c", map_[i][j]);
        }
        printf("\n");
    }
}

