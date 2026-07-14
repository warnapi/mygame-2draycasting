//
// Created by warnap on 13.06.2026.
//
#include "game.h"


Game::Game(std::vector<std::reference_wrapper<Player>>& arrayOfPlayers) : map(), arrayOfPlayers_(arrayOfPlayers),
                                                                          miniMapRender(map, arrayOfPlayers) {
}


void Game::MovePlayer(sf::Vector2f vector, unsigned int idOfPlayer) {
    arrayOfPlayers_.at(idOfPlayer).get().movePlayer(vector, this->map);
}

void Game::draw(sf::RenderWindow& window, bool event) {
    window.clear();
    miniMapRender.draw(window, event);
    window.display();
}

void Game::RotatePlayer(sf::Angle angle, unsigned int idOfPlayer) {
    arrayOfPlayers_.at(idOfPlayer).get().rotatePlayer(angle);
}

