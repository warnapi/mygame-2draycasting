//
// Created by warnap on 13.06.2026.
//
#include "game.h"


Game::Game(Vector PositionOfPlayer, unsigned int idOfPlayer) : player(Player{PositionOfPlayer, idOfPlayer}), map(Map{&(this->player)}) {}


void Game::MovePlayer(Vector vector) {
    this->player.vector += vector;
}

void Game::draw(sf::RenderWindow& window, std::vector<std::unique_ptr<sf::Drawable>>& container) {
    window.clear();
    window.draw();
    window.display();
}

void Game::init(std::vector<std::unique_ptr<sf::Drawable>>& container) {
    sf::RectangleShape mapOnScreen({width_of_map*30, height_of_map*30});
    mapOnScreen.setPosition({1000.f,500.f});
    mapOnScreen.setFillColor(sf::Color::White);
}
