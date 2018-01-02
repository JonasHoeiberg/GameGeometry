//
// Created by jonas on 12/29/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H

#include "math/vector_types.h"
#include <cmath>

namespace Math {
    inline float cos(float rad) {return std::cos(rad);}

    inline float sin(float rad) {return std::sin(rad);}

    inline float dot(const Vector2f& vec1, const Vector2f& vec2) {
        return (vec1.x * vec2.x) + (vec1.y * vec2.y);
    }

    inline float dot(const Vector3f& vec1, const Vector3f& vec2) {
        return (vec1.x * vec2.x ) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
    }

    inline float length2(const Vector2f& vec) {
        return dot(vec, vec);
    }

    inline float length2(const Vector3f& vec) {
        return dot(vec, vec);
    }

    inline float length(const Vector2f& vec) {
        return std::sqrt(length2(vec));
    }

    inline float length(const Vector3f& vec) {
        return std::sqrt(length2(vec));
    }

    inline Vector2f normalize(const Vector2f& vec) {
        return vec / length(vec);
    }

    inline Vector3f normalize(const Vector3f& vec) {
        return vec / length(vec);
    }
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
