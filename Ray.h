//
// Created by achateauricherd on 04/03/2020.
//

#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Line.h"

class Ray : public sf::Drawable
{
protected:
    sf::Vector2f origin;
    sf::Vector2f direction;

    void draw(sf::RenderTarget &, sf::RenderStates) const override;

public:
    Ray() = default;
    explicit Ray(const int x = 0, const int y = 0, const float angle = 0)
        : origin(x, y), direction(std::cos(angle), std::sin(angle))
    {}

    Ray(const int x1, const int y1, const int x2, const int y2)
        : origin(x1, y1)
    {
        direction = utils::normalize(sf::Vector2f(x2 - x1, y2 - y1));
    }

    const sf::Vector2f &getOrigin() const
    {
        return origin;
    }
    const sf::Vector2f &getDirection() const
    {
        return direction;
    }

    std::unique_ptr<sf::Vector2f> cast(const Line &) const;
};


#endif //RAY_H
