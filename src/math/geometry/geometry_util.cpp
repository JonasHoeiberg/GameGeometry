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

        if (length2(projection) > length2(point - lineSegment.a) && length2(point - lineSegment.a) < length2(point - lineSegment.b))
            return lineSegment.a;
        else if (length2(projection) > length2(point - lineSegment.b) && length2(point - lineSegment.b) < length2(point - lineSegment.a))
            return lineSegment.b;

        return projection;
    }
}