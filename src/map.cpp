//
// Created by warnap on 12.06.2026.
//

#include "map.h"

Map::Map() {
    for (int i = 0; i < height_of_map; i++) {
        for (int j = 0; j < width_of_map; ++j) {
            if(i == 0 || j == 0 || i == height_of_map-1 || j == width_of_map-1 || (j*j - 15*j + 3 > i && j > 3)) {
                map_[i][j] = '#';
            } else {
                map_[i][j] = ' ';
            }
        }
    }

    auto mapOnScreen = std::make_unique<sf::RectangleShape>(sf::Vector2f {width_of_map*coefficient, height_of_map*coefficient});

    mapOnScreen->setPosition(StartPos);
    mapOnScreen->setFillColor(sf::Color::Blue);
    this->mapContainer.push_back(std::move(mapOnScreen));                       //map back init
    for (int y = 0; y < height_of_map; ++y) {
        for (int x = 0; x < width_of_map; ++x) {
            if(this->getBlock(x,y)) {
                auto block  = std::make_unique<sf::RectangleShape>(sf::Vector2f{coefficient-(int)(2*thicknessOfBoarders),coefficient-(int)(2*thicknessOfBoarders)});
                block->setPosition(StartPos + sf::Vector2f{(float)x*coefficient + thicknessOfBoarders,(float)y*coefficient + thicknessOfBoarders});
                block->setFillColor(sf::Color::Red);
                block->setOutlineThickness(thicknessOfBoarders);
                block->setOutlineColor(sf::Color::White);
                mapContainer.push_back(std::move(block));
            }
        }
    }
}

bool Map::getBlock(int x, int y) {
    if (x < 0 || y < 0 || x >= width_of_map || y >= height_of_map || this->map_[y][x] == '#')
        return true;
    else
        return false;
}
bool Map::getBlock(sf::Vector2f vector) {
    if ((int)(vector.x) < 0 || (int)(vector.y) < 0 || (int)(vector.x) >= width_of_map || (int)(vector.y) >= height_of_map || this->map_[(int)(vector.y)][(int)vector.x] == '#'
    || this->map_[(int)(vector.y+1)][(int)vector.x] == '#'  || this->map_[(int)(vector.y)][(int)vector.x+1] == '#'  || this->map_[(int)(vector.y+1)][(int)vector.x+1] == '#') {
        return true;
    }
    else{
        return false;
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (int i = 0; i < mapContainer.size(); i++)
        window.draw(*mapContainer[i]);
}
