//
// Created by jonas on 12/24/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H

#include "shape2d.h"
#include "math/vector_types.h"
#include "math/matrix_types.h"
#include <vector>

//TODO: Replace std vector with own collection

namespace Math {
    struct Polygon2D : public Shape2D {
        explicit Polygon2D(const std::vector<Vector2f>& vertices);

        Polygon2D transform(const Matrix3x3f& mat);

        ShapeType getType() const override {
            return ShapeType::SHAPE_2D_POLYGON;
        }

        const Vector2f& operator[](size_t index) const {
            return vertices.at(index);
        }

        size_t count() const {
            return vertices.size();
        }

        const Vector2f center;

        Polygon2D toPolygon()const override;
        Bounding2D toBoundingBox()const override;

    private:
        const std::vector<Vector2f> vertices;

        Vector2f findCenter();
    };
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_CONVEX_POLYGON2D_H
