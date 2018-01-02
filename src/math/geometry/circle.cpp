//
// Created by jonas on 12/23/17.
//

#include <math.h>
#include "math/math_util.h"
#include "math/geometry/shapes2d.h"

#define CIRCLE_POLYGON_COUNT 360

namespace GG {
    Polygon2D Circle::toPolygon() const {
        std::vector<Vector2f> vectors = std::vector<Vector2f>(CIRCLE_POLYGON_COUNT);

        for (int i = 0; i < CIRCLE_POLYGON_COUNT; i++) {
            double rad = ((float) i / (float) CIRCLE_POLYGON_COUNT) * 2.0f * M_PI;

            vectors[i] = center + (radius * Vector2f(GG::cos(rad), GG::sin(rad)));
        }

        return Polygon2D(vectors);
    }

    Bounding2D Circle::toBoundingBox() const {
        return Bounding2D(center.x - radius,center.x + radius, center.y + radius, center.y - radius);
    }
}