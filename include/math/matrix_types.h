//
// Created by jonas on 12/23/17.
//

#ifndef GAMEGEOMETRY_MATRIX_TYPES_H
#define GAMEGEOMETRY_MATRIX_TYPES_H

#include <cstdint>
#include <memory.h>
#include <array>

#ifdef GLM_CONVERSIONS
#include <glm/glm.hpp>
#endif //GLM_CONVERSIONS

namespace GG {
    struct Vector3f;

    struct Matrix3x3f {
        Matrix3x3f() = default;
        explicit Matrix3x3f(const std::array<float, 9>& array) {
            memcpy(vals,&array[0],sizeof(float) * 9);
        }

        explicit Matrix3x3f(float val) {
            std::fill_n(vals, 9, val);
        }

        float& operator[](uint32_t index) {
            return vals[index];
        }

        const float& operator[](uint32_t index) const {
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

        friend Matrix3x3f operator*(const Matrix3x3f& lhs, const Matrix3x3f& rhs) {
            Matrix3x3f mat = Matrix3x3f(0.0f);

            for (int i = 0; i < 9; i++) {
                int k = (i / 3) * 3;
                for (int j = i % 3; j < 9; j += 3) {
                    mat[i] += lhs[k] * rhs[j];
                    k++;
                }
            }

            return mat;
        }

    protected:
        float vals[9] = {   1.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 1.0f};
    };
}


#endif //GAMEGEOMETRY_MATRIX_TYPES_H
