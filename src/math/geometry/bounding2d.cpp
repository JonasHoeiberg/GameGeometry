//
// Created by jonas on 12/23/17.
//

#include "math/geometry/bounding2d.h"
#include "math/geometry/polygon2d.h"

namespace GG {
    Polygon2D Bounding2D::toPolygon() const {
        return Polygon2D({
                Vector2f(left, top),
                Vector2f(right, top),
                Vector2f(right, bottom),
                Vector2f(left, bottom)
                               });
    }

    Bounding2D Bounding2D::toBoundingBox() const {
        return *this;
    }
}