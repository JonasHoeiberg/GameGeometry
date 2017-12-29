//
// Created by jonas on 12/24/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H

#include "shape2d.h"
#include "math_include.h"
#include <vector>

//TODO: Replace std vector with own collection

namespace Math {
    struct Polygon2D : public Shape2D {
        Polygon2D(const std::vector<Vector2f>& vertices);

        Polygon2D transform(const Matrix3x3f& mat);
        const std::vector<Vector2f> vertices;

        ShapeType getType() const override {
            return ShapeType::SHAPE_2D_POLYGON;
        }

        Polygon2D toPolygon()const override;
        Bounding2D toBoundingBox()const override;

        bool isConvex();
    private:
        bool convex = false;
    };
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H
