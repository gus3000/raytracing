//
// Created by achateauricherd on 05/03/2020.
//

#ifndef OPERATORS_H
#define OPERATORS_H


#include <SFML/System/Vector2.hpp>
#include <ostream>

std::ostream &operator<<(std::ostream &o, sf::Vector2f const &v);

template<typename T>
sf::Vector2<T> operator*(sf::Vector2<T> const &v, float mul)
{
    return {static_cast<T>(v.x * mul), static_cast<T>(v.y * mul)};
}

template<typename T>
sf::Vector2<T> operator*(float mul, sf::Vector2<T> const &v)
{
    return v * mul;
}

template<typename T>
sf::Vector2<T> operator/(sf::Vector2<T> const &v, float div)
{
    return {static_cast<T>(v.x / div), static_cast<T>(v.y / div)};
}


#endif //OPERATORS_H
