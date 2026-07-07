//
// Created by warnap on 06.07.2026.
//

#ifndef PERSON_GAMES_VECTOR_H
#define PERSON_GAMES_VECTOR_H

struct Vector {
    float x,y;
    Vector(float x, float y);
    Vector operator+(const Vector& other) const;
    Vector operator*(const Vector& other) const;
    Vector operator*(const float& other) const;
    Vector& operator+=(const Vector& other);
    Vector& operator*=(const Vector& other);
};

#endif //PERSON_GAMES_VECTOR_H
