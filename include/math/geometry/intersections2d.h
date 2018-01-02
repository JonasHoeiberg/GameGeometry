//
// Created by jonas on 12/29/17.
//

#ifndef GAMEGEOMETRY_COLLISION_H
#define GAMEGEOMETRY_COLLISION_H

#include "math/geometry/geometry2d.h"
#include "math/geometry/shapes2d.h"
#include "math/geometry/lines2d.h"

namespace GG {
    //Some templating to ensure function argument order doesn't matter
    template<class T, class S>
    bool intersect(const T &geom1, const S &geom2);

    //Geometry
    template<class T>
    bool intersect(const T& geom1, const Geometry2D& geom2);

    bool intersect(const Geometry2D& geom1, const Geometry2D& geom2);
    bool intersect(const Geometry2D& geom, const Shape2D& shape);

    bool intersect(const LineSegment2D& lineSegment1, const LineSegment2D& lineSegment2);
    bool intersect(const LineSegment2D& lineSegment, const Line2D& line);
    bool intersect(const LineSegment2D& lineSegment, const Polygon2D& poly);
    bool intersect(const LineSegment2D& lineSegment, const Bounding2D& bounding);
    bool intersect(const LineSegment2D& lineSegment, const Circle& circle);

    bool intersect(const Line2D& line1, const Line2D& line2);
    bool intersect(const Line2D& line, const Polygon2D& poly);
    bool intersect(const Line2D& line, const Bounding2D& bounding);
    bool intersect(const Line2D& line, const Circle& circle);

    //Shapes
    template<class T>
    bool intersect(const T& shape1, const Shape2D& shape2);

    bool intersect(const Shape2D& shape1, const Shape2D& shape2);

    bool intersect(const Polygon2D &poly1, const Polygon2D &poly2);
    bool intersect(const Polygon2D& poly, const Circle& circle);
    bool intersect(const Polygon2D& poly, const Bounding2D& aabb);

    bool intersect(const Bounding2D& aabb, const Circle& circle);
    bool intersect(const Bounding2D& aabb1, const Bounding2D& aabb2);

    bool intersect(const Circle& circle1, const Circle& circle2);
}


#endif //GAMEGEOMETRY_COLLISION_H
