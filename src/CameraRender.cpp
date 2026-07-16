//
// Created by warnap on 15.07.2026.
//

#include "CameraRender.h"

CameraRender::CameraRender(std::vector<RayInfo>& arrOfSizeOfRays, sf::Vector2i sizeofWindow) : arrOfSizeOfRays_(arrOfSizeOfRays), sizeofWindow_(sizeofWindow){
    initLines();
}

void CameraRender::initLines() {
    for (int i = 0; i < arrOfSizeOfRays_.size(); ++i) {
        auto line = sf::RectangleShape(calculateLineSize(arrOfSizeOfRays_[i].distance));
        line.setPosition(calculatePosition(line.getSize(), i));
        line.setFillColor(calculateDarkness(arrOfSizeOfRays_[i], sf::Color::Red));
        arrOfLineShapes_.push_back(std::move(line));
    }
}

sf::Vector2f CameraRender::calculateLineSize(float distance) {
    return sf::Vector2f {(float)sizeofWindow_.x/POV,(1/distance)*(float)sizeofWindow_.y};
}

sf::Vector2f CameraRender::calculatePosition(sf::Vector2f sizeOfLine, int index) {
    return sf::Vector2f{(float)sizeofWindow_.x - ((float)sizeofWindow_.x/POV)*(float)index,(((float)sizeofWindow_.y - sizeOfLine.y)/2)};
}

sf::Color CameraRender::calculateDarkness(RayInfo distance, sf::Color baseColor) {
    if (!distance.hit) {
        return sf::Color::Black;
    }
    float intensity = 1.f - (distance.distance/VisibilityRange);
    return sf::Color{
            static_cast<std::uint8_t>(baseColor.r * intensity),
            static_cast<std::uint8_t>(baseColor.g * intensity),
            static_cast<std::uint8_t>(baseColor.b * intensity),
            baseColor.a
    };
}

void CameraRender::draw(sf::RenderWindow& window, bool event) {
    if (event) {updateShapes();}
    for (int i = 0; i < arrOfLineShapes_.size(); ++i) {
        window.draw(arrOfLineShapes_[i]);
    }
}

void CameraRender::updateShapes() {
    for (int i = 0; i < arrOfLineShapes_.size(); ++i) {
        arrOfLineShapes_[i].setSize(calculateLineSize(arrOfSizeOfRays_[i].distance));
        arrOfLineShapes_[i].setPosition(calculatePosition(arrOfLineShapes_[i].getSize(), i));
        arrOfLineShapes_[i].setFillColor(calculateDarkness(arrOfSizeOfRays_[i], sf::Color::Red));
    }
}

