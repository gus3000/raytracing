//
// Created by achateauricherd on 04/03/2020.
//

#ifndef RAY_H
#define RAY_H

#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "Line.h"

class Ray : public sf::Drawable {
protected:
    sf::Vector2f origin;
    sf::Vector2f direction;

    void draw(sf::RenderTarget &, sf::RenderStates) const override;

public:
    Ray() = default;

    explicit Ray(const float x, const float y, const float angle = 0)
            : origin(x, y), direction(std::cos(angle), std::sin(angle)) {}

    explicit Ray(const sf::Vector2f &origin, const float angle = 0)
            : Ray(origin.x, origin.y, angle) {}

    Ray(const float x1, const float y1, const float x2, const float y2)
            : origin(x1, y1) {
        direction = utils::normalize(sf::Vector2f(x2 - x1, y2 - y1));
    }

    Ray(const sf::Vector2f &origin, const sf::Vector2f &direction)
            : Ray(origin.x, origin.y, direction.x, direction.y) {}

    [[nodiscard]] const sf::Vector2f &getOrigin() const;
    [[nodiscard]] const sf::Vector2f &getDirection() const;
    [[nodiscard]] float getAngle() const;

    [[nodiscard]] sf::Vector2f* cast(const Line &) const;
    [[nodiscard]] sf::Vector2f* cast(const Obstacle &) const;

    bool operator==(const Ray &rhs) const;
    bool operator!=(const Ray &rhs) const;

};


#endif //RAY_H
