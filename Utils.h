//
// Created by achateauricherd on 05/03/2020.
//

#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <random>
#include <limits>

#include "operators.h"
#include "Light.h"

//class Light;
class Line;

class Obstacle;

namespace utils
{
const float EPSILON = std::numeric_limits<float>::epsilon() * 1000;

const std::string RESOURCES_DIRECTORY = "res/";

const std::string FONTS_DIRECTORY = RESOURCES_DIRECTORY + "fonts/";

// shape stuff
void setPositionCentered(sf::CircleShape &cs, const sf::Vector2f &v);
void setPositionCentered(sf::Sprite &s, const sf::Vector2f &v);
void setPositionCentered(Obstacle &o, const sf::Vector2f &v);

// sf::Vector stuff
template<typename T>
float dist(sf::Vector2<T> v)
{
    return std::hypot(v.x, v.y);
}

template<typename T>
float dist(sf::Vector2<T> v1, sf::Vector2<T> v2)
{
    float dx = v2.x - v1.x;
    float dy = v2.y - v1.y;
    return std::hypot(dx, dy);

}
sf::Vector2f normalize(sf::Vector2f v);
bool almostEqual(sf::Vector2f v1, sf::Vector2f v2);
bool almostEqual(const Line &l1, const Line &l2);
sf::Vector2f randomPoint(float xMin, float yMin, float xMax, float yMax);

// collection stuff
template<typename T>
bool in_array(T key, std::vector<T> array)
{
    return std::find(array.begin(), array.end(), key) != array.end();
}

bool in_array(sf::Vector2f key, std::vector<sf::Vector2f> array);
bool in_array(Line key, std::vector<Line> array);

template<typename T>
bool remove_duplicates(std::vector<T> array)
{
    std::vector<T> noDups;
    for (auto &elem : array)
        if (!in_array(elem, noDups))
            noDups.emplace_back(elem);
    return noDups;
}

//random stuff
Line randomLine(float xMin, float yMin, float xMax, float yMax);

}

#endif //UTILS_H
