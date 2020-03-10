//
// Created by achateauricherd on 05/03/2020.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H


#include <SFML/Graphics.hpp>
#include <utility>

class Line;

class Obstacle: public sf::Drawable
{
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
protected:
    std::vector<sf::Vector2f> points;
public:
    Obstacle() = default;
    explicit Obstacle(std::vector<sf::Vector2f> points)
        : points(std::move(points))
    {}

    [[nodiscard]] const std::vector<sf::Vector2f> &getPoints() const
    {
        return points;
    }

    void addPoint(sf::Vector2f p)
    {
        points.emplace_back(p);
    }
    [[nodiscard]] virtual sf::Vector2f *intersect(const Obstacle &) const = 0;

    [[nodiscard]] std::vector<Line> getLines() const;
};

std::ostream &operator<<(std::ostream &o, const Obstacle &obstacle);
std::ostream &operator<<(std::ostream &o, const Obstacle *obstacle);
std::ostream &operator<<(std::ostream &o, std::unique_ptr<Obstacle> obstacle);


#endif //OBSTACLE_H
