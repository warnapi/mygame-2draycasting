//
// Created by warnap on 13.07.2026.
//

#ifndef PERSON_GAMES_MINIMAPRENDER_H
#define PERSON_GAMES_MINIMAPRENDER_H

#include "map.h"
#include "player.h"

class MiniMapRender {
private:
    Map& map_;
    std::vector<std::reference_wrapper<Player>>& arrayOfPlayers_;
    void changeShapesOfPlayer(int index);
    float rayCalculating(sf::Vector2f PosOnMapOfRay, sf::Angle angle1);
    void calculatePlayers();
    void renderMap();
    void renderPlayer(std::reference_wrapper<Player> Player);
    std::vector<std::vector<float>> arrOfSizeOfRays;
    std::vector<std::unique_ptr<sf::RectangleShape>> mapContainer_;
    std::vector<std::unique_ptr<sf::CircleShape>> ballOfPlayersOnMap_;
    std::vector<std::vector<std::unique_ptr<sf::RectangleShape>>> raysOfPlayersContainer_;
public:
    MiniMapRender(Map& map, std::vector<std::reference_wrapper<Player>> &arrayOfPlayers);
    void draw(sf::RenderWindow &window, bool event);
};


#endif //PERSON_GAMES_MINIMAPRENDER_H
