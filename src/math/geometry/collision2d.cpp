//
// Created by jonas on 12/29/17.
//

#include "math/geometry/collision2d.h"
#include "math/math_util.h"

namespace Math {

    bool intersect(const Polygon2D &poly1, const Polygon2D &poly2) {
        return false;
    }

    bool intersect(const Polygon2D &poly, const Circle &circle) {
        return false;
    }

    bool intersect(const Polygon2D &poly, const Bounding2D &aabb) {
        return intersect(poly, aabb.toPolygon());
    }

    bool intersect(const Bounding2D &aabb, const Polygon2D &poly) {
        return intersect(poly, aabb);
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

    bool intersect(const Circle &circle, const Polygon2D &poly) {
        return intersect(poly, circle);
    }

    bool intersect(const Circle &circle1, const Circle &circle2) {
        Vector2f ab = circle1.center - circle2.center;
        float radius2 = circle1.radius + circle2.radius;
        radius2 *= radius2;

        return dot(ab, ab) <= radius2;
    }

    bool intersect(const Circle &circle, const Bounding2D &aabb) {
        return intersect(aabb, circle);
    }

    template<class T>
    bool intersect(const T& shape1, const Shape2D& shape2) {
        switch (shape2.getType()) {
            case ShapeType::SHAPE_2D_POLYGON :  {
                auto poly2 = dynamic_cast<const Polygon2D&>(shape2);
                return intersect(shape1, poly2);
            }
            case ShapeType::SHAPE_2D_AABB : {
                auto aabb2 = dynamic_cast<const Bounding2D&>(shape2);
                return intersect(shape1, aabb2);
            }
            case ShapeType::SHAPE_2D_CIRCLE : {
                auto circle2 = dynamic_cast<const Circle&>(shape2);
                return intersect(shape1, circle2);
            }
        }

        return false;
    }

    template<class T>
    bool intersect(const Shape2D& shape1, const T& shape2) {
        return intersect<T>(shape2, shape1);
    }

    bool intersect(const Shape2D &shape1, const Shape2D &shape2) {
        switch(shape1.getType()) {
            case ShapeType::SHAPE_2D_POLYGON : {
                auto poly1 = dynamic_cast<const Polygon2D&>(shape1);

                return intersect(poly1, shape2);
            }
            case ShapeType::SHAPE_2D_CIRCLE : {
                auto circle1 = dynamic_cast<const Circle&>(shape1);

                return intersect(circle1, shape2);
            }
            case ShapeType::SHAPE_2D_AABB : {
                auto aabb1 = dynamic_cast<const Bounding2D&>(shape1);

                return intersect(aabb1, shape2);
            }
        }

        return false;
    }

    bool Math::intersect(const LineSegment2D &line1, const LineSegment2D &line2) {
        return false;
    }
}