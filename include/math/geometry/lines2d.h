//
// Created by Jonas on 30-12-2017.
//

#ifndef GAMEGEOMETRY_LINESEGMENT_H
#define GAMEGEOMETRY_LINESEGMENT_H

#include <math_include.h>

namespace GG {
    struct Line2D {
        Vector2f p;
        Vector2f dir;
    };

    struct LineSegment2D {
        Vector2f a;
        Vector2f b;

        inline Line2D getLine() const {
            return Line2D{.p = a, .dir = normalize(b - a)};
        }
    };
}


#endif //GAMEGEOMETRY_LINESEGMENT_H
