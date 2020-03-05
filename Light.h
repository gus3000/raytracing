//
// Created by achateauricherd on 05/03/2020.
//

#ifndef LIGHT_H
#define LIGHT_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Utils.h"

class Ray;

class Light: public sf::Drawable
{
protected:
    sf::Vector2f position;
    std::vector<Ray> rays;
    int radius;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        sf::CircleShape circle(radius);
        circle.setPosition(position);
        target.draw(circle);
    }

public:
    template<typename T>
    explicit Light(sf::Vector2<T> position, int radius = 15)
        : radius(radius)
    {
        setPosition(position);
    }

    template<typename T>
    void setPosition(sf::Vector2<T> v)
    {
        position = sf::Vector2f{v.x - radius, v.y - radius};
    }

    int getRadius() const;

};


#endif //LIGHT_H
