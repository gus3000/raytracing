//
// Created by achateauricherd on 05/03/2020.
//

#include "Obstacle.h"

void Obstacle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    std::vector<sf::Vertex> vertices;
    for (auto &p : getPoints()) {
        vertices.emplace_back(sf::Vertex(p));
    }
    target.draw(vertices.data(), vertices.size(), sf::Lines);
}
