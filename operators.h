//
// Created by achateauricherd on 05/03/2020.
//

#ifndef OPERATORS_H
#define OPERATORS_H


#include<SFML/System/Vector2.hpp>
#include <ostream>
#include <vector>
#include <deque>
#include <cmath>
#include <memory>

class Ray;

template<typename T>
std::ostream &operator<<(std::ostream &o, sf::Vector2<T> const &v)
{
    o << "{" << v.x << ", " << v.y << "}";
    return o;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, sf::Vector2<T*> const &v)
{
    o << "{" << v->x << ", " << v->y << "}";
    return o;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, sf::Vector2<std::unique_ptr<T>> const &v)
{
    o << "{" << v->x << ", " << v->y << "}";
    return o;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, std::deque<T> const &d)
{
    o << "{";
    for (int i = 0; i < d.size(); ++i) {
        o << d[i];
        if (i < d.size() - 1)
            o << ", ";
    }
    o << "}";
    return o;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, std::vector<std::unique_ptr<T>> const &d)
{
    o << "{";
    for (int i = 0; i < d.size(); ++i) {
        o << *d[i];
        if (i < d.size() - 1)
            o << ", ";
    }
    o << "}";
    return o;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, std::vector<T> const &d)
{
    o << "{";
    for (int i = 0; i < d.size(); ++i) {
        o << d[i];
        if (i < d.size() - 1)
            o << ", ";
    }
    o << "}";
    return o;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream &o, std::pair<T1,T2> const &p)
{
    return o << "pair<" << p.first << "," << p.second << ">";
}

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

struct Orderer
{
    //arbitrary comparisons, that don't make sense semantically but are useful for sets, etc
    template<typename T>
    bool operator()(const sf::Vector2<T> &v1, const sf::Vector2<T> &v2) const
    {
        return std::hypot(v1.x, v1.y) < std::hypot(v2.x, v2.y);
    }

    bool operator()(const Ray &v1, const Ray &v2) const;
};

//sf::Vector2u operator/(sf::Vector2u const &v, float div)
//{
//    return {static_cast<unsigned int>(v.x / div), static_cast<unsigned int>(v.y / div)};
//}


#endif //OPERATORS_H
