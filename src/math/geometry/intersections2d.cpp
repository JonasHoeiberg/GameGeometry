//
// Created by jonas on 12/29/17.
//

#include "math/geometry/intersections2d.h"
#include "math/math_util.h"
#include "math/geometry/geometry_util.h"

namespace GG {

    bool intersect(const Polygon2D &poly1, const Polygon2D &poly2) {
        //TODO: Sweep for possible pairs

        for (int i = 0; i < poly1.count(); i++) {
            int j = (i + 1) % poly1.count();
            for (int k = 0; k < poly2.count(); k++) {
                int l = (k + 1) % poly2.count();

                if (intersect(
                        LineSegment2D{.a = poly1[i], .b = poly1[j]},
                        LineSegment2D{.a = poly2[k], .b = poly2[l]}
                )) {
                    return true;
                }
            }
        }

        return false;
    }

    bool intersect(const Polygon2D &poly, const Circle &circle) {
        for (int i = 0; i < poly.count(); i++) {
            int j = (i + 1) % poly.count();

            //TODO: Move this to new function for circle-linesegment intersection
            float radius2 = circle.radius * circle.radius;

            float vert1Length = length2(poly[i] - circle.center);
            float vert2Length = length2(poly[j] - circle.center);

            if (vert1Length < radius2 && vert2Length < radius2) {
                continue;
            } else if (vert1Length > radius2 && vert2Length > radius2) {
                //TODO: Replace with overlap when it's available
                Vector2f approach = nearestApproach(circle.center, LineSegment2D{.a = poly[i], .b = poly[j]});

                if (length2(approach - circle.center) <= radius2) {
                    return true;
                }
            }
            else {
                return true;
            }
        }

        return false;
    }

    bool intersect(const Polygon2D &poly, const Bounding2D &aabb) {
        return intersect(poly, aabb.toPolygon());
    }

    bool intersect(const Bounding2D &aabb, const Circle &circle) {
        return intersect(aabb.toPolygon(), circle);
    }

    bool intersect(const Bounding2D &aabb1, const Bounding2D &aabb2) {
        return !(
                aabb1.right < aabb2.left ||
                aabb1.left > aabb2.right ||
                aabb1.bottom > aabb2.top ||
                aabb1.top < aabb2.bottom
        );
    }

    bool intersect(const Circle &circle1, const Circle &circle2) {
        Vector2f ab = circle1.center - circle2.center;
        float radius2 = circle1.radius + circle2.radius;
        radius2 *= radius2;

        return dot(ab, ab) <= radius2;
    }

    template<class T>
    bool intersect(const T& shape1, const Shape2D& shape2) {
        switch (shape2.getShapeType()) {
            case ShapeType2D::SHAPE_2D_POLYGON :  {
                auto poly2 = dynamic_cast<const Polygon2D&>(shape2);
                return intersect(shape1, poly2);
            }
            case ShapeType2D::SHAPE_2D_AABB : {
                auto aabb2 = dynamic_cast<const Bounding2D&>(shape2);
                return intersect(shape1, aabb2);
            }
            case ShapeType2D::SHAPE_2D_CIRCLE : {
                auto circle2 = dynamic_cast<const Circle&>(shape2);
                return intersect(shape1, circle2);
            }
        }

        return false;
    }

    template<class T, class S>
    bool intersect(const T &geom1, const S &geom2) {
        return intersect(geom2, geom1);
    }

    bool intersect(const Shape2D &shape1, const Shape2D &shape2) {
        switch(shape1.getShapeType()) {
            case ShapeType2D::SHAPE_2D_POLYGON : {
                auto poly1 = dynamic_cast<const Polygon2D&>(shape1);

                return intersect(poly1, shape2);
            }
            case ShapeType2D::SHAPE_2D_CIRCLE : {
                auto circle1 = dynamic_cast<const Circle&>(shape1);

                return intersect(circle1, shape2);
            }
            case ShapeType2D::SHAPE_2D_AABB : {
                auto aabb1 = dynamic_cast<const Bounding2D&>(shape1);

                return intersect(aabb1, shape2);
            }
        }

        return false;
    }

    bool intersect(const LineSegment2D &lineSegment1, const LineSegment2D &lineSegment2) {
        Line2D line1 = lineSegment1.getLine();
        Line2D line2 = lineSegment2.getLine();

        if (abs(dot(line1.dir, line2.dir)) == 1.0f) {
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
}