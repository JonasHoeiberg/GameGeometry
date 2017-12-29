//
// Created by jonas on 12/23/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H

#include <cstdint>

#ifdef GLM_CONVERSIONS
#include <glm/glm.hpp>
#endif //GLM_CONVERSIONS

namespace Math {
    struct Vector3f;

    struct Matrix3x3f {
        Matrix3x3f() = default;

        float& operator[](uint32_t index) {
            return vals[index];
        }

        Vector3f getColumnVector(uint32_t index) const;
        Vector3f getRowVector(uint32_t index) const;

        //TODO: GLM mat3 conversion not implemented
        #ifdef GLM_CONVERSIONS
            explicit Matrix3x3f(const glm::fmat3x3 glmMat){
                static_assert(false, "Conversion to/from GLM matrices is not yet implemented")
            }

            friend glm::fmat3x3 operator=(Matrix3x3f mat) {
                static_assert(false, "Conversion to/from GLM matrices is not yet implemented")
            }
        #endif

    private:
        float vals[9] = {   1.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 1.0f};
    };
}


#endif //SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H
