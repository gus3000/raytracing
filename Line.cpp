//
// Created by achateauricherd on 05/03/2020.
//

#include "Line.h"
#include "Utils.h"

using utils::EPSILON;

std::ostream &operator<<(std::ostream &o, const Line &l)
{
    o << "Line(" << l.getStart() << " -> " << l.getEnd() << ")";
    return o;
}
sf::Vector2f *Line::intersect(const Obstacle &) const
{
    std::cout << "intersect with obstacle" << std::endl;
    return nullptr;
}
sf::Vector2f *Line::intersect(const Line &l) const
{
    const sf::Vector2f p1 = getStart(), p2 = getEnd(),
        p3 = l.getStart(), p4 = l.getEnd();

    const float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
    if (den == 0) {
//        std::cout << __FUNCTION__ << " -> parallel lines :" << p1 << "->" << p2 << " and " << wall << std::endl;
//        std::cout << __FUNCTION__ << " current ray : " << origin << ", " << direction << std::endl;
        return nullptr;
    }

    const float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
    const float u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;
    // if u c [0,1], the intersection is on the line
    // if t > 0, the intersection is on the correct side of the ray
//    std::cout << "u = " << u << ", t = " << t << ", den = " << den << std::endl;
    if (t > -EPSILON && t < 1 + EPSILON && u > -EPSILON && u < 1 + EPSILON)
        return new sf::Vector2f(
            p1.x + t * (p2.x - p1.x),
            p1.y + t * (p2.y - p1.y));

    return nullptr;
}
std::pair<Line, Line> Line::split(sf::Vector2f point)
{
    return std::pair<Line, Line>(Line(getStart(), point), Line(point, getEnd()));
}
