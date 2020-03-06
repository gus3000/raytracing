//
// Created by achateauricherd on 05/03/2020.
//

#include "Light.h"
#include "Ray.h"


int Light::getRadius() const {
    return radius;
}

void Light::cast(const std::vector<std::unique_ptr<Obstacle>> &obstacles) {
//    std::cout << "Casting light at " << position << "\n";
    rays.clear();
    impacts.clear();
    for (auto &obstacle : obstacles) {
        auto points = (*obstacle).getPoints();
        for (auto &point : points) {
            Ray r(position, point);
            rays.emplace_back(r);
        }
    }

    impacts.resize(rays.size());
//    for (auto &ray: rays) {
    for (int i = 0; i < rays.size(); ++i) {
//        std::cout << __FUNCTION__ << " with i = " << i << std::endl;
        auto &ray = rays[i];
        float minDistance = INFINITY;
        sf::Vector2f *nearestImpact = nullptr;
        for (auto &obstacle : obstacles) {
            sf::Vector2f *impact = ray.cast(*obstacle);
            if (impact == nullptr)
                continue;
            float distance = utils::dist(position, *impact);
            if (distance < minDistance) {
//                std::cout << "\tnew distance found : " << distance << std::endl;
                minDistance = distance;
                delete nearestImpact;
                nearestImpact = impact;
//                nearestImpact.swap(impact);
            }
        }
        if (nearestImpact == nullptr)
            impacts[i] = nullptr;
        else
            impacts[i] = std::make_unique<sf::Vector2f>(nearestImpact->x, nearestImpact->y);
        delete nearestImpact;
//        std::cout << __FUNCTION__ << " adding " << (impacts[i]) << std::endl;
    }
}

void Light::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::CircleShape circle(radius);
    circle.setPosition(position);
    target.draw(circle);
    sf::Vector2f offsetPosition = {position.x + radius, position.y + radius};
//    std::cout << impacts << std::endl;
    for (auto &impact : impacts) {
        if (impact != nullptr) {
//            target.draw(Line(position, *impact));
            sf::Vertex vertices[] = {
                    sf::Vertex(offsetPosition, sf::Color(255,255,255,128)),
                    sf::Vertex(*impact, sf::Color(255,255,255,128)),

            };
            target.draw(vertices, 2, sf::Lines);
            sf::CircleShape impactShape(5,8);
            utils::setPositionCentered(impactShape,*impact);
            target.draw(impactShape);
        }
    }
}
