//
// Created by jonas on 12/23/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H

#include <glm/glm.hpp>

namespace Math {
    class Matrix3x3f : public glm::fmat3x3 {
        Matrix3x3f(){}
        Matrix3x3f(const glm::fmat3x3 glmMat):glm::fmat3x3(glmMat){}

        Matrix3x3f operator=(const glm::fmat3x3 glmMat) {
            return Matrix3x3f(glmMat);
        }
    };
}


#endif //SERIOUSENGINEFORSERIOUSPEOPLE_MATRIX_TYPES_H
