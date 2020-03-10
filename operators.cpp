//
// Created by achateauricherd on 10/03/2020.
//

#include "operators.h"
#include "Ray.h"

bool Orderer::operator()(const Ray &v1, const Ray &v2) const
{
    return v1.getAngle() < v2.getAngle();

}