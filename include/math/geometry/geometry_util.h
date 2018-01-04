//
// Created by Jonas on 01-01-2018.
//

#ifndef GAMEGEOMETRY_GEOMETRY_UTIL_H
#define GAMEGEOMETRY_GEOMETRY_UTIL_H

#include "math_include.h"
#include "math/geometry/lines2d.h"

namespace GG {

    Vector2f project(const Vector2f& point, const Line2D& line);

    inline bool oppositeSides(const Vector2f& dir, const Vector2f& a, const Vector2f& b) {
        Vector2f orth = Vector2f(-dir.y, dir.x);

        float sin1 = dot(orth, a);
        float sin2 = dot(orth, b);

        if (sin1 == 0.0f || sin2 == 0.0f) {
            return true;
        }

        return std::signbit(sin1) != std::signbit(sin2);
    }
}

#endif //GAMEGEOMETRY_GEOMETRY_UTIL_H
