//
// Created by achateauricherd on 04/03/2020.
//

#include "Ray.h"


using std::unique_ptr;

void Ray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Vertex line[] = {
        sf::Vertex(origin),
        sf::Vertex(origin + direction * 10),
    };
    target.draw(line, 2, sf::Lines);
}

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
unique_ptr<sf::Vector2f> Ray::cast(const Line &wall) const
{
    const sf::Vector2f p1 = origin, p2 = origin + direction,
        p3 = wall.getStart(), p4 = wall.getEnd();

    const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
    if (den == 0)
        return nullptr;

    const float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
    const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;
    // if u c [0,1], the intersection is on the line
    // if t > 0, the intersection is on the correct side of the ray
//    std::cout << "u = " << u << ", t = " << t << ", den = " << den << std::endl;
    if (t > 0 && u > 0 && u < 1)
        return std::make_unique<sf::Vector2f>(
            p1.x + t * (p2.x - p1.x),
            p1.y + t * (p2.y - p1.y));

    return nullptr;
}
