//
// Created by achateauricherd on 05/03/2020.
//

#ifndef LINE_H
#define LINE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "operators.h"
#include "Obstacle.h"

class Line: public Obstacle
{
protected:
//    sf::Vector2f start;
//    sf::Vector2f end;
public:
    Line(const sf::Vector2f &start, const sf::Vector2f &end)
        : Obstacle({start, end})
    {}

    const sf::Vector2f &getStart() const
    {
        return points[0];
    }
    const sf::Vector2f &getEnd() const
    {
        return points[1];
    }
    [[nodiscard]] virtual sf::Vector2f *intersect(const Obstacle &) const override;
    [[nodiscard]] virtual sf::Vector2f *intersect(const Line &) const;
    std::pair<Line,Line> split(sf::Vector2f point);

    //friends
    friend std::ostream &operator<<(std::ostream &o, const Line &l);
};

std::ostream &operator<<(std::ostream &o, const Line &l);

#endif //LINE_H
