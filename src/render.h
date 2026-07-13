//
// Created by warnap on 13.07.2026.
//

#ifndef PERSON_GAMES_RENDER_H
#define PERSON_GAMES_RENDER_H

#include "map.h"
#include "player.h"

class Render {
private:
    void changeShapesOfPlayer(int index);
    float rayCalculating(sf::Vector2f PosOnMapOfRay, sf::Angle angle1);
    void calculatePlayers();
    void renderMap(Map& map);
    void renderPlayer(std::reference_wrapper<Player> Player);
    std::vector<std::vector<float>> arrOfSizeOfRays;
    std::vector<std::unique_ptr<sf::RectangleShape>> mapContainer_;
    std::vector<std::unique_ptr<sf::CircleShape>> ballOfPlayersOnMap_;
    std::vector<std::vector<std::unique_ptr<sf::RectangleShape>>> raysOfPlayersContainer_;
    std::vector<std::reference_wrapper<Player>> arrayOfPlayers_;
    Map& map_;
public:
    explicit Render(Map &map,std::vector<std::reference_wrapper<Player>> arrayOfPlayers);
    void draw(sf::RenderWindow &window, bool event);
};


#endif //PERSON_GAMES_RENDER_H
