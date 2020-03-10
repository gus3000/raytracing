//
// Created by achateauricherd on 04/03/2020.
//

#include "Ray.h"
#include "Utils.h"


using std::unique_ptr;
using utils::EPSILON;

void Ray::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Vertex line[] = {
        sf::Vertex(origin),
        sf::Vertex(origin + direction * 10),
    };
    target.draw(line, 2, sf::Lines);
}

// https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
sf::Vector2f *Ray::cast(const Line &wall) const
{
//    std::cout << __FUNCTION__ << " line " << std::endl;
    const sf::Vector2f p1 = origin, p2 = origin + direction,
        p3 = wall.getStart(), p4 = wall.getEnd();

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
    if (t > -EPSILON && u > -EPSILON && u < 1 + EPSILON)
        return new sf::Vector2f(
            p1.x + t * (p2.x - p1.x),
            p1.y + t * (p2.y - p1.y));

    return nullptr;
}

sf::Vector2f *Ray::cast(const Obstacle &obstacle) const
{
//    std::cout << __FUNCTION__ << std::endl;
    const auto &points = obstacle.getPoints();
    float minDistance = INFINITY;
    sf::Vector2f *nearestImpact = nullptr;
    for (int i = 0; i < points.size() - 1; ++i) {
        sf::Vector2f *pos = cast(Line(points[i], points[i + 1]));
        if (pos == nullptr)
            continue;
//        std::cout << "\t" << *pos << std::endl;
        float distance = utils::dist(origin, *pos);
        if (distance < minDistance) {
//            std::cout << "\t[obstacle] new distance found : " << distance << std::endl;
            minDistance = distance;
            delete nearestImpact;
            nearestImpact = pos;
//            nearestImpact.swap(pos);
        }
    }
//    std::cout << __FUNCTION__ << " returning " << nearestImpact << std::endl;
    return nearestImpact;
}
bool Ray::operator==(const Ray &rhs) const
{
    return origin == rhs.origin &&
        direction == rhs.direction;
}
bool Ray::operator!=(const Ray &rhs) const
{
    return !(rhs == *this);
}
const sf::Vector2f &Ray::getOrigin() const
{
    return origin;
}
const sf::Vector2f &Ray::getDirection() const
{
    return direction;
}
float Ray::getAngle() const
{
    return std::atan2(direction.y, direction.x);
}
