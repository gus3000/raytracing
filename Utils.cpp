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
    sf::Vector2u delta = s.getTexture()->getSize() / 2;
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
    //TODO
    return sf::Vector2f();
}

