//
// Created by jonas on 12/29/17.
//

#include <limits>
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

            if (intersect(circle, LineSegment2D(poly[i], poly[j]))) {
                return true;
            }
        }

        return false;
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
                auto& poly2 = dynamic_cast<const Polygon2D&>(shape2);
                return intersect(shape1, poly2);
            }
            case ShapeType2D::SHAPE_2D_AABB : {
                auto& aabb2 = dynamic_cast<const Bounding2D&>(shape2);
                return intersect(shape1, aabb2);
            }
            case ShapeType2D::SHAPE_2D_CIRCLE : {
                auto& circle2 = dynamic_cast<const Circle&>(shape2);
                return intersect(shape1, circle2);
            }
        }

        return false;
    }

    bool intersect(const Shape2D &shape1, const Shape2D &shape2) {
        switch(shape1.getShapeType()) {
            case ShapeType2D::SHAPE_2D_POLYGON : {
                auto& poly1 = dynamic_cast<const Polygon2D&>(shape1);

                return intersect(poly1, shape2);
            }
            case ShapeType2D::SHAPE_2D_CIRCLE : {
                auto& circle1 = dynamic_cast<const Circle&>(shape1);

                return intersect(circle1, shape2);
            }
            case ShapeType2D::SHAPE_2D_AABB : {
                auto& aabb1 = dynamic_cast<const Bounding2D&>(shape1);

                return intersect(aabb1, shape2);
            }
        }

        return false;
    }

    template<class T>
    bool intersect(const T &geom1, const Geometry2D &geom2) {
        switch(geom2.getGeometryType()) {
            case GeometryType2D::GEOMETRY_2D_LINE : {
                auto& line = dynamic_cast<const Line2D&>(geom2);
                return intersect(geom1, line);
            }
            case GeometryType2D::GEOMETRY_2D_LINE_SEGMENT : {
                auto& lineSegment = dynamic_cast<const LineSegment2D&>(geom2);
                return intersect(geom1, lineSegment);
            }
            case GeometryType2D::GEOMETRY_2D_SHAPE : {
                auto& shape = dynamic_cast<const Shape2D&>(geom2);
                return intersect(geom1, shape);
            }
        }

        return false;
    }

    bool intersect(const Geometry2D &geom1, const Geometry2D &geom2) {
        switch(geom1.getGeometryType()) {
            case GeometryType2D::GEOMETRY_2D_LINE : {
                auto& line = dynamic_cast<const Line2D&>(geom1);
                return intersect(line, geom2);
            }
            case GeometryType2D::GEOMETRY_2D_LINE_SEGMENT : {
                auto& lineSegment = dynamic_cast<const LineSegment2D&>(geom1);
                return intersect(lineSegment, geom2);
            }
            case GeometryType2D::GEOMETRY_2D_SHAPE : {
                auto& shape = dynamic_cast<const Shape2D&>(geom1);
                return intersect(shape, geom2);
            }
        }
    }

    bool intersect(const LineSegment2D &lineSegment, const Polygon2D &poly) {
        for (int i = 0; i < poly.count(); i++) {
            int j = (j + 1) % poly.count();

            if (intersect(
                    lineSegment,
                    LineSegment2D{.a = poly[i], .b = poly[j]}
            )) {
                return true;
            }
        }
    }

    bool intersect(const Line2D &line, const Polygon2D &poly) {
        for (int i = 0; i < poly.count(); i++) {
            int j = (j + 1) % poly.count();

            if (oppositeSides(line.dir, poly[i] - line.p, poly[j] - line.p)) {
                return true;
            }
        }

        return false;
    }
}