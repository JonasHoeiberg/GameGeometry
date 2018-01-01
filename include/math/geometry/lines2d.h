//
// Created by Jonas on 30-12-2017.
//

#ifndef GAMEGEOMETRY_LINESEGMENT_H
#define GAMEGEOMETRY_LINESEGMENT_H

#include "math/vector_types.h"

namespace Math {
    struct LineSegment2D {
        Vector2f a;
        Vector2f b;
    };

    struct Line2D {
        Vector2f p;
        Vector2f dir;
    };
}


#endif //GAMEGEOMETRY_LINESEGMENT_H
