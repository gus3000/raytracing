//
// Created by achateauricherd on 05/03/2020.
//

#ifndef LIGHT_H
#define LIGHT_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Utils.h"
#include "Line.h"
#include "Obstacle.h"

class Ray;

class Light : public sf::Drawable {
protected:
    sf::Vector2f position;
    std::vector<Ray> rays;
    std::vector<std::unique_ptr<sf::Vector2f>> impacts;
    int radius;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    template<typename T>
    explicit Light(sf::Vector2<T> position, int radius = 15)
            : radius(radius) {
        setPosition(position);
    }

    template<typename T>
    void setPosition(sf::Vector2<T> v) {
        position = sf::Vector2f{static_cast<float>(v.x - radius), static_cast<float>(v.y - radius)};
    }

    int getRadius() const;

    void cast(const std::vector<std::unique_ptr<Obstacle>> &obstacles);

};


#endif //LIGHT_H
