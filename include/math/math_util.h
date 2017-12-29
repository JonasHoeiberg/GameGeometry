//
// Created by jonas on 12/29/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H

#include <cmath>
#include "vector_types.h"

namespace Math {
    float cos(float rad) {return std::cos(rad);}

    float sin(float rad) {return std::sin(rad);}

    float dot(Vector2f vec1, Vector2f vec2) {
        return (vec1.x * vec2.x) + (vec1.y + vec2.y);
    }
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
