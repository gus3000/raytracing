//
// Created by achateauricherd on 05/03/2020.
//

#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <random>

#include "operators.h"
#include "Light.h"

//class Light;
class Line;

class Obstacle;

namespace utils {
    const float EPSILON = FLT_EPSILON * 1000;
    const std::string RESOURCES_DIRECTORY = "res/";
    const std::string FONTS_DIRECTORY = RESOURCES_DIRECTORY + "fonts/";

    void setPositionCentered(sf::CircleShape &cs, const sf::Vector2f &v);

    void setPositionCentered(sf::Sprite &s, const sf::Vector2f &v);

    void setPositionCentered(Obstacle &o, const sf::Vector2f &v);

//template<typename T>
//void setPositionCentered(T &shape, float x, float y)
//{
//    utils::setPositionCentered(shape, sf::Vector2f(x, y));
//}

    template<typename T>
    float dist(sf::Vector2<T> v) {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    template<typename T>
    float dist(sf::Vector2<T> v1, sf::Vector2<T> v2) {
        float dx = v2.x - v1.x;
        float dy = v2.y - v1.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    sf::Vector2f normalize(sf::Vector2f v);

    sf::Vector2f randomPoint(float xMin, float yMin, float xMax, float yMax);

    Line randomLine(float xMin, float yMin, float xMax, float yMax);

}

#endif //UTILS_H
