//
// Created by warnap on 13.07.2026.
//

#include "render.h"

Render::Render(Map& map, std::vector<std::reference_wrapper<Player>> arrayOfPlayers) : map_(map){
    //инициализация всех игроков
    for (int j = 0; j < arrayOfPlayers.size(); ++j) {

        renderPlayer(arrayOfPlayers[j]);
    }
    //инициализация мапы
    renderMap(map);
}

void Render::renderPlayer(std::reference_wrapper<Player> Player) {
    sf::Vector2f currentPosition = Player.get().getPosition();
    arrayOfPlayers_.push_back(std::ref(Player));
    arrOfSizeOfRays.emplace_back();
    auto CircleOfPlayer = std::make_unique<sf::CircleShape>(coefficient/2);
    CircleOfPlayer->setFillColor(sf::Color::Cyan);
    CircleOfPlayer->setPosition(PosOfMap + sf::Vector2f{currentPosition.x*coefficient, currentPosition.y*coefficient});
    ballOfPlayersOnMap_.push_back(std::move(CircleOfPlayer));

    sf::Vector2f centerOfPlayer = sf::Vector2f{PosOfMap.x + currentPosition.x*coefficient + coefficient/2,
                                               PosOfMap.y + currentPosition.y*coefficient + coefficient/2};
    raysOfPlayersContainer_.emplace_back();
    for(int n = 0; n < POV; ++n) {
        arrOfSizeOfRays.back().push_back(rayCalculating(currentPosition + sf::Vector2f{0.5f,0.5f},
                                                        sf::Angle{Player.get().getAngle() - (sf::degrees(n))}));
        auto ray = std::make_unique<sf::RectangleShape>(sf::Vector2f{arrOfSizeOfRays.back().back()*coefficient, sizeOfLine});
        ray->setFillColor(sf::Color::Green);
        ray->setPosition(sf::Vector2f{centerOfPlayer} - sf::Vector2f{0, sizeOfLine/2});
        ray->setOrigin(sf::Vector2f{0, sizeOfLine/2});
        ray->setRotation(sf::Angle{Player.get().getAngle() - (sf::degrees(n))});
        raysOfPlayersContainer_.back().push_back(std::move(ray));
    }
}

void Render::renderMap(Map &map) {
    auto background = std::make_unique<sf::RectangleShape>(sf::Vector2f {width_of_map*coefficient, height_of_map*coefficient});
    background->setPosition(PosOfMap);
    background->setFillColor(sf::Color::Blue);
    mapContainer_.push_back(std::move(background));
    for (int y = 0; y < height_of_map; ++y) {
        for (int x = 0; x < width_of_map; ++x) {
            if(map_.getBlock(x,y)) {
                auto block = std::make_unique<sf::RectangleShape>(sf::Vector2f{coefficient-(int)(2*thicknessOfBoarders),coefficient-(int)(2*thicknessOfBoarders)});
                block->setPosition(PosOfMap + sf::Vector2f{(float)x*coefficient + thicknessOfBoarders,(float)y*coefficient + thicknessOfBoarders});
                block->setFillColor(sf::Color::Red);
                block->setOutlineThickness(thicknessOfBoarders);
                block->setOutlineColor(sf::Color::White);
                mapContainer_.push_back(std::move(block));
            }
        }
    }
}

float Render::rayCalculating(sf::Vector2f PosOnMapOfRay, sf::Angle angle1) {
    sf::Vector2f normalizedVector = {(float)cos(angle1.asRadians()), (float)sin(angle1.asRadians())};
    sf::Vector2f distToNextBlock;
    if (normalizedVector.x == 0) {
        distToNextBlock.x = 1e30f;
    } else {
        distToNextBlock.x = (float)sqrt(1 + (normalizedVector.y/normalizedVector.x)*(normalizedVector.y/normalizedVector.x));
    }
    if (normalizedVector.y == 0) {
        distToNextBlock.y = 1e30f;
    } else {
        distToNextBlock.y = (float) sqrt(1 + (normalizedVector.x / normalizedVector.y) * (normalizedVector.x / normalizedVector.y));
    }
    sf::Vector2i directionOfMoving;
    sf::Vector2f mainDistanceToNextBlock;
    if (normalizedVector.x < 0) {
        directionOfMoving.x = -1;
        mainDistanceToNextBlock.x = (PosOnMapOfRay.x - (int)PosOnMapOfRay.x)*distToNextBlock.x;
    } else {
        directionOfMoving.x = 1;
        mainDistanceToNextBlock.x = ((int)PosOnMapOfRay.x+1 - PosOnMapOfRay.x)*distToNextBlock.x;
    }
    if (normalizedVector.y < 0) {
        directionOfMoving.y = -1;
        mainDistanceToNextBlock.y = (PosOnMapOfRay.y - (int)PosOnMapOfRay.y)*distToNextBlock.y;
    } else {
        directionOfMoving.y = 1;
        mainDistanceToNextBlock.y = ((int)PosOnMapOfRay.y+1 - PosOnMapOfRay.y)*distToNextBlock.y;
    }
    float actualDistance = 0;
    sf::Vector2i actualPosition = sf::Vector2i {(int)PosOnMapOfRay.x,(int)PosOnMapOfRay.y};
    bool hit = 0;
    while (!hit) {
        if(mainDistanceToNextBlock.x < mainDistanceToNextBlock.y) {
            mainDistanceToNextBlock.x += distToNextBlock.x;
            actualDistance = mainDistanceToNextBlock.x;
            actualPosition.x += directionOfMoving.x;
        } else {
            mainDistanceToNextBlock.y += distToNextBlock.y;
            actualDistance = mainDistanceToNextBlock.y;
            actualPosition.y += directionOfMoving.y;
        }
        if (map_.getBlock(actualPosition.x,actualPosition.y)) {
            hit = 1;
        }
        if(actualDistance > VisibilityRange) {
            return VisibilityRange;
        }
    }
    return actualDistance;
}

void Render::draw(sf::RenderWindow &window, bool event) {
    if (event) calculatePlayers();

    for (int i = 0; i < mapContainer_.size(); ++i) {
        window.draw(*mapContainer_[i]);
    }
    for (int i = 0; i < raysOfPlayersContainer_.size(); i++) {
        for (int n = 0; n < raysOfPlayersContainer_[i].size(); ++n) {
            window.draw(*raysOfPlayersContainer_[i][n]);
        }
    }
    for (int i = 0; i < ballOfPlayersOnMap_.size(); ++i) {
        window.draw(*ballOfPlayersOnMap_[i]);
    }
}

void Render::calculatePlayers() {
    for (int j = 0; j < arrayOfPlayers_.size(); ++j) {
        changeShapesOfPlayer(j);
    }
}

void Render::changeShapesOfPlayer(int index) {
    Player& currentPlayer = arrayOfPlayers_[index];
    sf::Vector2f currentPosition = currentPlayer.getPosition();
    sf::Vector2f centerOfPlayer = sf::Vector2f{PosOfMap.x + currentPosition.x*coefficient + coefficient/2,
                                               PosOfMap.y + currentPosition.y*coefficient + coefficient/2};

    for (int i = 0; i < raysOfPlayersContainer_[index].size(); ++i) {
        arrOfSizeOfRays[index][i] = (rayCalculating(currentPosition + sf::Vector2f{0.5f,0.5f},
                                                        sf::Angle{currentPlayer.getAngle() - (sf::degrees(i))}));
        raysOfPlayersContainer_[index][i].get()->setSize({arrOfSizeOfRays[index][i]*coefficient, sizeOfLine});
        raysOfPlayersContainer_[index][i].get()->setRotation(sf::Angle{sf::degrees(currentPlayer.getAngle().asDegrees()) - sf::degrees(i)});
        raysOfPlayersContainer_[index][i].get()->setPosition(sf::Vector2f{centerOfPlayer} - sf::Vector2f{0, sizeOfLine/2});
    }
    ballOfPlayersOnMap_[index].get()->setPosition(PosOfMap + sf::Vector2f{currentPosition.x*coefficient, currentPosition.y*coefficient});
}