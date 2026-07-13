//
// Created by warnap on 13.06.2026.
//
#include "game.h"


Game::Game(sf::Vector2f PositionOfPlayer, unsigned int idOfPlayer) {

}


void Game::MovePlayer(sf::Vector2f vector) {
    player.movePlayer(vector, this->map);
}

void Game::draw(sf::RenderWindow& window, bool event) {
    window.clear();
    map.draw(window, event);
    player.draw(window, map);
    window.display();
}

void Game::RotatePlayer(sf::Angle angle) {
   player.rotatePlayer(angle);
}

