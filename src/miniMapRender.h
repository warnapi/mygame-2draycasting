//
// Created by warnap on 13.07.2026.
//

#ifndef PERSON_GAMES_MINIMAPRENDER_H
#define PERSON_GAMES_MINIMAPRENDER_H

#include "map.h"
#include "player.h"
#include "rayInfo.h"
class MiniMapRender {
private:
    Map& map_;
    std::vector<std::reference_wrapper<Player>>& arrayOfPlayers_;
    void changeShapesOfPlayer(int index);
    RayInfo rayCalculating(sf::Vector2f PosOnMapOfRay, sf::Angle angle1);

    void renderMap();
    void renderPlayer(std::reference_wrapper<Player> Player);
    std::vector<RayInfo> arrOfSizeOfRays_;
    std::vector<std::unique_ptr<sf::RectangleShape>> mapContainer_;
    std::vector<std::unique_ptr<sf::CircleShape>> ballOfPlayersOnMap_;
    std::vector<std::vector<std::unique_ptr<sf::RectangleShape>>> raysOfPlayersContainer_;
public:
    void calculatePlayers();
    MiniMapRender(Map& map, std::vector<std::reference_wrapper<Player>> &arrayOfPlayers);
    void draw(sf::RenderWindow &window, bool event);
    std::vector<RayInfo>& getArrOfSizeOfRays();
};



#endif //PERSON_GAMES_MINIMAPRENDER_H
