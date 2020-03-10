//
// Created by achateauricherd on 05/03/2020.
//

#include "Obstacle.h"
#include "Line.h"
#include "Utils.h"


void Obstacle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    std::vector<sf::Vertex> vertices;
    for (auto &p : getPoints()) {
        vertices.emplace_back(sf::Vertex(p));
    }
    target.draw(vertices.data(), vertices.size(), sf::Lines);

    for (auto &p : getPoints()) {
        sf::CircleShape c(5);
        utils::setPositionCentered(c, p);
        target.draw(c);
    }
}
std::vector<Line> Obstacle::getLines() const
{
    if (points.size() < 2)
        return std::vector<Line>();

    std::vector<Line> lines;
    for (int i = 0; i < points.size() - 1; ++i) {
        lines.emplace_back(points[i], points[i + 1]);
    }

    return lines;
}

std::ostream &operator<<(std::ostream &o, const Obstacle &obstacle)
{
    const auto& points = obstacle.getPoints();
    if(points.empty())
        return o << "{}";
    o << "{";
//    for (auto &p : obstacle.getPoints())
    for (int i = 0; i < points.size()-1; ++i)
        o << points[i] << ", ";
    o << *(points.end()-1) << "}";
    return o;
}

std::ostream &operator<<(std::ostream &o, const Obstacle *obstacle)
{
    return o << *obstacle;
}

std::ostream &operator<<(std::ostream &o, std::unique_ptr<Obstacle> obstacle)
{
    return o << *obstacle;
}