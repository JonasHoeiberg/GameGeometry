//
// Created by jonas on 12/23/17.
//

#include "math/geometry/circle.h"
#include "math/geometry/polygon2d.h"
#include "math/geometry/bounding2d.h"
#include "math_include.h"

#define CIRCLE_POLYGON_COUNT 360

namespace Math {
    Polygon2D Circle::toPolygon() const {
        std::vector<Vector2f> vectors = std::vector<Vector2f>(CIRCLE_POLYGON_COUNT);

        for (float i = 0; i < CIRCLE_POLYGON_COUNT; i += 1.0f) {
            double rad = (i / (float) CIRCLE_POLYGON_COUNT) * 2 * M_PI;

            vectors[i] = center + (radius * Vector2f(Math::cos(rad), Math::sin(rad)));
        }

        return Polygon2D(vectors);
    }

    Bounding2D Circle::toBoundingBox() const {
        return Bounding2D(center.x - radius,center.x + radius, center.y + radius, center.y - radius);
    }
}