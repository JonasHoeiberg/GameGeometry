//
// Created by jonas on 12/29/17.
//

#include "math/geometry/collision2d.h"
#include "math/math_util.h"

namespace Math {

    bool overlap(const Polygon2D &poly1, const Polygon2D &poly2) {
        return false;
    }

    bool overlap(const Polygon2D &poly, const Circle &circle) {
        return false;
    }

    bool overlap(const Polygon2D &poly, const Bounding2D &aabb) {
        return false;
    }

    bool overlap(const Bounding2D &aabb, const Polygon2D &poly) {
        return overlap(poly, aabb);
    }

    bool overlap(const Bounding2D &aabb, const Circle &circle) {
        return false;
    }

    bool overlap(const Bounding2D &aabb1, const Bounding2D &aabb2) {
        return false;
    }

    bool overlap(const Circle &circle, const Polygon2D &poly) {
        return overlap(poly, circle);
    }

    bool overlap(const Circle &circle1, const Circle &circle2) {
        Vector2f ab = circle1.center - circle2.center;
        float radius2 = circle1.radius + circle2.radius;
        radius2 *= radius2;

        return dot(ab, ab) <= radius2;
    }

    bool overlap(const Circle &circle, const Bounding2D &aabb) {
        return overlap(aabb, circle);
    }

    template<class T>
    bool overlap(const T& shape1, const Shape2D& shape2) {
        switch (shape2.getType()) {
            case ShapeType::SHAPE_2D_POLYGON :  {
                auto poly2 = dynamic_cast<const Polygon2D&>(shape2);
                return overlap(shape1, poly2);
            }
            case ShapeType::SHAPE_2D_AABB : {
                auto aabb2 = dynamic_cast<const Bounding2D&>(shape2);
                return overlap(shape1, aabb2);
            }
            case ShapeType::SHAPE_2D_CIRCLE : {
                auto circle2 = dynamic_cast<const Circle&>(shape2);
                return overlap(shape1, circle2);
            }
        }

        return false;
    }

    template<class T>
    bool overlap(const Shape2D& shape1, const T& shape2) {
        return overlap<T>(shape2, shape1);
    }

    bool overlap(const Shape2D &shape1, const Shape2D &shape2) {
        switch(shape1.getType()) {
            case ShapeType::SHAPE_2D_POLYGON : {
                auto poly1 = dynamic_cast<const Polygon2D&>(shape1);

                return overlap(poly1, shape2);
            }
            case ShapeType::SHAPE_2D_CIRCLE : {
                auto circle1 = dynamic_cast<const Circle&>(shape1);

                return overlap(circle1, shape2);
            }
            case ShapeType::SHAPE_2D_AABB : {
                auto aabb1 = dynamic_cast<const Bounding2D&>(shape1);

                return overlap(aabb1, shape2);
            }
        }

        return false;
    }
}