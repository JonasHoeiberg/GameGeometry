//
// Created by jonas on 12/23/17.
//

#include "math/matrix_types.h"
#include "math/vector_types.h"

namespace Math {
    Vector3f Matrix3x3f::getColumnVector(uint32_t index) const {
        return Vector3f{
                .x = vals[index],
                .y = vals[index + 3],
                .z = vals[index + 6]
        };
    };

    Vector3f Matrix3x3f::getRowVector(uint32_t index) const {
        return Vector3f{
                .x = vals[index * 3],
                .y = vals[index * 3 + 1],
                .z = vals[index * 3 + 2]
        };
    };
}