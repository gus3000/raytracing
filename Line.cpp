//
// Created by achateauricherd on 05/03/2020.
//

#include "Line.h"

std::ostream &operator<<(std::ostream &o, const Line &l)
{
    o << "[" << l.getStart() << " -> " << l.getEnd() << "]";
    return o;
}