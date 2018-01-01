//
// Created by Jonas on 01-01-2018.
//

#ifndef GAMEGEOMETRY_GEOMETRY_UTIL_H
#define GAMEGEOMETRY_GEOMETRY_UTIL_H

#include "math_include.h"
#include "math/geometry/lines2d.h"

namespace Math {

    Vector2f project(const Vector2f& point, const Line2D& line);
    //Returns a t value for the line rather than the projection position
    float tProject(const Vector2f& point, const Line2D& line);

    Vector2f nearestApproach(const Vector2f& point, const Line2D& line);
    Vector2f nearestApproach(const Vector2f& point, const LineSegment2D& lineSegment);
}

#endif //GAMEGEOMETRY_GEOMETRY_UTIL_H
