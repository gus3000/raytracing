//
// Created by achateauricherd on 05/03/2020.
//

#include "Utils.h"
#include "Line.h"
#include "Light.h"

std::ostream &operator<<(std::ostream &o, const sf::Vector2f &v)
{
    o << "{" << v.x << ", " << v.y << "}";
    return o;
}

void utils::setPositionCentered(sf::Sprite &s, const sf::Vector2f &v)
{
    sf::Vector2u size = s.getTexture()->getSize();
    sf::Vector2f delta = {size.x / 2.f, size.y / 2.f};
    s.setPosition(v.x - delta.x, v.y - delta.y);
}

void utils::setPositionCentered(sf::CircleShape &cs, const sf::Vector2f &v)
{
    sf::Vector2f offset = {cs.getRadius(), cs.getRadius()};
    cs.setPosition(v - offset);
}

Line utils::randomLine(float xMin, float yMin, float xMax, float yMax)
{
    return Line(randomPoint(xMin, yMin, xMax, yMax), randomPoint(xMin, yMin, xMax, yMax));
}

sf::Vector2f utils::randomPoint(float xMin, float yMin, float xMax, float yMax)
{
    static std::random_device r;
    static std::default_random_engine engine(r());
    std::uniform_real_distribution<float> distX(xMin, xMax);
    std::uniform_real_distribution<float> distY(yMin, yMax);

    return {distX(engine), distY(engine)};
}

sf::Vector2f utils::normalize(sf::Vector2f v)
{
    return v / dist(v);
}
bool utils::in_array(sf::Vector2f key, std::vector<sf::Vector2f> array)
{
    for (auto &v : array)
        if (almostEqual(key, v))
            return true;
    return false;
}
bool utils::in_array(Line key, std::vector<Line> array)
{
    for (auto &l : array)
        if (almostEqual(key, l))
            return true;
    return false;
}
bool utils::almostEqual(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::abs(v1.x - v2.x) < EPSILON && std::abs(v1.y - v2.y) < EPSILON;
}
bool utils::almostEqual(const Line &l1, const Line &l2)
{
    return (almostEqual(l1.getStart(), l2.getStart()) && almostEqual(l1.getEnd(), l2.getEnd()))
        || (almostEqual(l1.getStart(), l2.getEnd()) && almostEqual(l1.getEnd(), l2.getStart()));
}
