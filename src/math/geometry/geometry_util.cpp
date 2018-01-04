//
// Created by Jonas on 01-01-2018.
//

#include "math/geometry/geometry_util.h"


#include "math_include.h"
#include "math/geometry/lines2d.h"

namespace GG {

    Vector2f project(const Vector2f &point, const Line2D &line) {
        Vector2f tPoint = point - line.p;

        return (dot(tPoint, line.dir) * line.dir) + line.p;
    }

}