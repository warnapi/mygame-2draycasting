//
// Created by warnap on 15.07.2026.
//

#ifndef PERSON_GAMES_CAMERARENDER_H
#define PERSON_GAMES_CAMERARENDER_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "game_const.h"
#include "rayInfo.h"
#include <cstdint>

class CameraRender {
private:
    sf::Vector2i sizeofWindow_;
    std::vector<RayInfo>& arrOfSizeOfRays_;
    std::vector<sf::RectangleShape> arrOfLineShapes_;
    void initLines();
    sf::Vector2f calculateLineSize(float distance);
    sf::Vector2f calculatePosition(sf::Vector2f sizeOfLine, int index);
    sf::Color calculateDarkness(RayInfo distance, sf::Color baseColor);
    void updateShapes();
public:
    void draw(sf::RenderWindow& window, bool event);
    CameraRender(std::vector<RayInfo>&  arrOfSizeOfRays, sf::Vector2i sizeofWindow);
};


#endif //PERSON_GAMES_CAMERARENDER_H
