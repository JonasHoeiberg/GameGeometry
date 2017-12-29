//
// Created by jonas on 12/29/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H

#include "glm/glm.hpp"
#include "vector_types.h"

namespace Math {
    template<typename T>
        T cos(T rad) {return glm::cos(rad);}

    template<typename T>
        T sin(T rad) {return glm::sin(rad);}

    float dot(Vector2f vec1, Vector2f vec2) {
        return (vec1.x * vec2.x) + (vec1.y + vec2.y);
    }
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
