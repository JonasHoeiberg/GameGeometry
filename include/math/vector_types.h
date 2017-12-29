//
// Created by jonas on 12/23/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H

#include <glm/glm.hpp>

namespace Math {
    struct Vector2f : public glm::fvec2 {
        Vector2f(){}
        Vector2f(const glm::fvec2 glmVec):glm::fvec2(glmVec){}
        Vector2f(const glm::fvec3 glmVec):glm::fvec2(glmVec){}
        Vector2f(float val):glm::fvec2(val){}
        Vector2f(float x, float y):glm::fvec2(x,y){}

        Vector2f operator=(const glm::fvec2& glmVec) {
            return Vector2f(glmVec);
        }
    };

    struct Vector3f : public glm::fvec3 {
        Vector3f(){}
        Vector3f(const glm::fvec3 glmVec):glm::fvec3(glmVec){}
        Vector3f(float val):glm::fvec3(val){}
        Vector3f(float x, float y, float z):glm::fvec3(x,y,z){}

        Vector3f operator=(const glm::fvec3& glmVec) {
            return Vector3f(glmVec);
        }
    };
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H
