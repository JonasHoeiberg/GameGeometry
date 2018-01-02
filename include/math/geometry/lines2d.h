//
// Created by Jonas on 30-12-2017.
//

#ifndef GAMEGEOMETRY_LINESEGMENT_H
#define GAMEGEOMETRY_LINESEGMENT_H

#include <math_include.h>
#include "math/geometry/geometry2d.h"

namespace GG {
    struct Line2D : public Geometry2D {
        Line2D(const Vector2f& p, const Vector2f& dir) :
            p(p),
            dir(dir)
        {

        }

        Line2D() = default;

        Vector2f p;
        Vector2f dir;

        GeometryType2D getGeometryType() const override {
            return GeometryType2D::GEOMETRY_2D_LINE;
        }
    };

    struct LineSegment2D : public Geometry2D {
        LineSegment2D(const Vector2f& a, const Vector2f& b) :
                a(a),
                b(b)
        {

        }

        LineSegment2D() = default;

        Vector2f a;
        Vector2f b;

        inline Line2D getLine() const {
            return Line2D{.p = a, .dir = normalize(b - a)};
        }

        GeometryType2D getGeometryType() const override {
                return GeometryType2D::GEOMETRY_2D_LINE_SEGMENT;
        }
    };
}


#endif //GAMEGEOMETRY_LINESEGMENT_H
