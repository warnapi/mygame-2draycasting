//
// Created by warnap on 06.07.2026.
//
#include "vector.h"

Vector Vector::operator+(const Vector& other) const {
    return {this->x + other.x, this->y + other.y};
}

Vector Vector::operator*(const Vector& other) const {
    return {this->x * other.x, this->y * other.y};
}

Vector& Vector::operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector& Vector::operator*=(const Vector& other) {
    this->x *= other.x;
    this->y *= other.y;
    return *this;
}

Vector::Vector(float x, float y) : x(x), y(y) {}

Vector Vector::operator*(const float &other) const {
    return {this->x * other, this->y * other};
}
