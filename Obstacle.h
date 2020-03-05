//
// Created by achateauricherd on 05/03/2020.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H


#include <SFML/Graphics.hpp>
#include <utility>

class Obstacle: public sf::Drawable
{
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override
    {
        std::vector<sf::Vertex> vertices;
        for (auto &p : getPoints()) {
            vertices.emplace_back(sf::Vertex(p));
        }
        target.draw(vertices.data(), vertices.size(), sf::Lines);
    }
protected:
    std::vector<sf::Vector2f> points;
public:
    Obstacle() = default;
    explicit Obstacle(std::vector<sf::Vector2f> points)
        : points(std::move(points))
    {}

    const std::vector<sf::Vector2f> &getPoints() const
    {
        return points;
    }

    void addPoint(sf::Vector2f p)
    {
        points.emplace_back(p);
    }
};


#endif //OBSTACLE_H
