//
// Created by jonas on 12/29/17.
//

#ifndef GAMEGEOMETRY_COLLISION_H
#define GAMEGEOMETRY_COLLISION_H

#include "math/geometry/geometry2d.h"
#include "math/geometry/shapes2d.h"
#include "math/geometry/lines2d.h"
#include "math/geometry/geometry_util.h"
#include "math/geometry/distance2d.h"

namespace GG {
    //Some templating to ensure function parameter order doesn't matter
    template<class T, class S,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type,
            class = typename std::enable_if<std::is_base_of<Geometry2D, S>::value>::type
    >
    inline bool intersect(const T &geom1, const S &geom2)  {
        return intersect(geom2, geom1);
    }

    //Geometry
    template<class T,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type
    >
    bool intersect(const T& geom1, const Geometry2D& geom2);

    bool intersect(const Geometry2D& geom1, const Geometry2D& geom2);

    //Line segment
    inline bool intersect(const LineSegment2D& lineSegment1, const LineSegment2D& lineSegment2) {
        Line2D line1 = lineSegment1.getLine();
        Line2D line2 = lineSegment2.getLine();

        if (abs(dot(line1.dir, line2.dir)) >= 1.0f - std::numeric_limits<float>::epsilon()) {
            return false;
        }

        if (!oppositeSides(line1.dir, lineSegment2.a - line1.p, lineSegment2.b - line1.p)) {
            return false;
        }

        if (!oppositeSides(line2.dir, lineSegment1.a - line2.p, lineSegment1.b - line2.p)) {
            return false;
        }

        return true;
    }

    inline bool intersect(const LineSegment2D& lineSegment, const Line2D& line) {
        return oppositeSides(line.dir, lineSegment.a - line.p, lineSegment.b - line.p);
    }

    bool intersect(const LineSegment2D& lineSegment, const Polygon2D& poly);

    inline bool intersect(const LineSegment2D& lineSegment, const Bounding2D& bounding)  {
        return intersect(lineSegment, bounding.toPolygon());
    }

    inline bool intersect(const LineSegment2D& lineSegment, const Circle& circle)  {
        float radius2 = circle.radius * circle.radius;

        float vert1Length = length2(lineSegment.a - circle.center);
        float vert2Length = length2(lineSegment.b - circle.center);

        if (vert1Length < radius2 && vert2Length < radius2) {
            return false;
        } else if (vert1Length > radius2 && vert2Length > radius2) {
            Vector2f approach = distanceVector(circle.center, lineSegment);

            return length2(approach - circle.center) <= radius2;
        }

        return true;
    }

    //Line
    inline bool intersect(const Line2D& line1, const Line2D& line2)  {
        return abs(dot(line1.dir, line2.dir)) > std::numeric_limits<float>::epsilon();
    }

    bool intersect(const Line2D& line, const Polygon2D& poly);

    inline bool intersect(const Line2D& line, const Bounding2D& bounding) {
        return intersect(line, bounding.toPolygon());
    }

    inline bool intersect(const Line2D& line, const Circle& circle) {
        Vector2f closest = project(circle.center, line);

        return length2(closest) <= circle.radius * circle.radius;
    }

    //Shape
    template<class T,
            class = typename std::enable_if<std::is_base_of<Geometry2D, T>::value>::type
    >
    bool intersect(const T& shape1, const Shape2D& shape2);

    bool intersect(const Shape2D& shape1, const Shape2D& shape2);

    //Polygon
    bool intersect(const Polygon2D &poly1, const Polygon2D &poly2);
    bool intersect(const Polygon2D& poly, const Circle& circle);

    inline bool intersect(const Polygon2D& poly, const Bounding2D& aabb) {
        return intersect(poly, aabb.toPolygon());
    }

    //Bounding box
    inline bool intersect(const Bounding2D& aabb, const Circle& circle) {
        return intersect(aabb.toPolygon(), circle);
    }

    inline bool intersect(const Bounding2D& aabb1, const Bounding2D& aabb2)  {
        return !(
                aabb1.right < aabb2.left ||
                aabb1.left > aabb2.right ||
                aabb1.bottom > aabb2.top ||
                aabb1.top < aabb2.bottom
        );
    }

    //Circle
    bool intersect(const Circle& circle1, const Circle& circle2);
}


#endif //GAMEGEOMETRY_COLLISION_H
