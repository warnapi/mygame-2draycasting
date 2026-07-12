//
// Created by warnap on 13.06.2026.
//
#include "game.h"


Game::Game(sf::Vector2f PositionOfPlayer, unsigned int idOfPlayer) : player(Player{PositionOfPlayer, idOfPlayer}) {}


void Game::MovePlayer(sf::Vector2f vector) {
    this->player.movePlayer(vector, this->map);
}

void Game::draw(sf::RenderWindow& window) {
    window.clear();
    this->map.draw(window);
    this->player.draw(window, this->map);
    window.display();
}

void Game::RotatePlayer(sf::Angle angle) {
   this->player.rotatePlayer(angle);
}

