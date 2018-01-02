//
// Created by Jonas on 01-01-2018.
//

#include "math/geometry/geometry_util.h"


#include "math/geometry/shapes2d.h"
#include "math_include.h"
#include "math/geometry/lines2d.h"

namespace Math {

    Vector2f project(const Vector2f &point, const Line2D &line) {
        Vector2f tPoint = point - line.p;

        return (dot(tPoint, line.dir) * line.dir) + line.p;
    }

    Vector2f nearestApproach(const Vector2f &point, const LineSegment2D &lineSegment) {
        Vector2f projection = project(point, lineSegment.getLine());
        float pa = length2(lineSegment.a - point);
        float pb = length2(lineSegment.b - point);

        if (    projection.x <= std::max(lineSegment.a.x, lineSegment.b.x) &&
                projection.x >= std::min(lineSegment.a.x, lineSegment.b.x) &&
                projection.y <= std::max(lineSegment.a.y, lineSegment.b.y) &&
                projection.y >= std::min(lineSegment.a.y, lineSegment.b.y)) {
            return projection;
        }

        if (pa < pb) {
            return lineSegment.a;
        }

        return lineSegment.b;
    }
}