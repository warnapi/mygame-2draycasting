//
// Created by warnap on 08.06.2026.
//

#ifndef PLAYER_GAMES_PLAYER_H
#define PLAYER_GAMES_PLAYER_H
#include "vector.h"

class Player {
private:
    unsigned int ID;
public:
    Player(Vector position, unsigned int id);

    Vector position;
    Vector vector;

    unsigned int getId() const;

    void setId(unsigned int id);
};


#endif

