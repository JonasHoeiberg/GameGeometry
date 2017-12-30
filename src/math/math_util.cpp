//
// Created by jonas on 12/29/17.
//

#include <cmath>
#include "math/vector_types.h"
#include "math/math_util.h"

namespace Math {
    float cos(float rad) {return std::cos(rad);}

    float sin(float rad) {return std::sin(rad);}

    float dot(const Vector2f& vec1, const Vector2f& vec2) {
        return (vec1.x * vec2.x) + (vec1.y + vec2.y);
    }

    float dot(const Vector3f& vec1, const Vector3f& vec2) {
        return (vec1.x * vec2.x ) + (vec1.y + vec2.y) + (vec1.z * vec2.z);
    }
}