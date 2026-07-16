//
// Created by warnap on 13.06.2026.
//

#ifndef PERSON_GAMES_GAME_H
#define PERSON_GAMES_GAME_H

#include <SFML/Graphics.hpp>
#include "map.h"
#include "player.h"
#include "miniMapRender.h"
#include "game_const.h"
#include "CameraRender.h"

class Game {
private:
    std::vector<std::reference_wrapper<Player>>& arrayOfPlayers_;
    Map map;
    MiniMapRender miniMapRender;
    CameraRender cameraRender;
public:

    void MovePlayer(sf::Vector2f vector, unsigned int idOfPlayer);
    void RotatePlayer(sf::Angle angle, unsigned int idOfPlayer);
    Game(std::vector<std::reference_wrapper<Player>>& arrayOfPlayers, sf::Vector2i sizeOfWindow);
    void draw(sf::RenderWindow& window, bool event);
};


#endif //PERSON_GAMES_GAME_H
