//
// Created by jonas on 12/29/17.
//

#ifndef GAMEGEOMETRY_COLLISION_H
#define GAMEGEOMETRY_COLLISION_H

#include "shapes2d.h"
#include "lines2d.h"

namespace GG {
    bool intersect(const Polygon2D &poly1, const Polygon2D &poly2);
    bool intersect(const Polygon2D& poly, const Circle& circle);
    bool intersect(const Polygon2D& poly, const Bounding2D& aabb);

    bool intersect(const Bounding2D& aabb, const Polygon2D& poly);
    bool intersect(const Bounding2D& aabb, const Circle& circle);
    bool intersect(const Bounding2D& aabb1, const Bounding2D& aabb2);

    bool intersect(const Circle& circle, const Polygon2D& poly);
    bool intersect(const Circle& circle1, const Circle& circle2);
    bool intersect(const Circle& circle, const Bounding2D& aabb);

    template<class T>
    bool intersect(const T& shape1, const Shape2D& shape2);

    template<class T>
    bool intersect(const Shape2D& shape2, const T& shape1);

    bool intersect(const Shape2D& shape1, const Shape2D& shape2);

    bool intersect(const LineSegment2D& line1, const LineSegment2D& line2);
}


#endif //GAMEGEOMETRY_COLLISION_H
