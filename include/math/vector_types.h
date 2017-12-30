//
// Created by jonas on 12/23/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H

#ifdef GLM_CONVERSIONS
    #include <glm/glm.hpp>
#endif //GLM_CONVERSIONS

#include "matrix_types.h"

namespace Math {


    struct Vector3f {
        float x = 0.0f, y = 0.0f, z = 0.0f;

        Vector3f():x(0.0f),y(0.0f),z(0.0f){}
        explicit Vector3f(float val):x(val),y(val),z(val){}
        Vector3f(float x, float y, float z):x(x),y(y),z(z){}

        friend Vector3f operator+(Vector3f lhs, const Vector3f& rhs) {
            lhs.x += rhs.x;
            lhs.y += rhs.y;
            lhs.z += rhs.z;

            return lhs;
        }

        friend Vector3f operator-(Vector3f lhs, const Vector3f& rhs) {
            lhs.x -= rhs.x;
            lhs.y -= rhs.y;
            lhs.z -= rhs.z;

            return lhs;
        }

        friend Vector3f operator*(Vector3f lhs, const Vector3f& rhs) {
            lhs.x *= rhs.x;
            lhs.y *= rhs.y;
            lhs.z *= rhs.z;

            return lhs;
        }

        friend Vector3f operator*(Vector3f vec, float scalar) {
            vec.x *= scalar;
            vec.y *= scalar;
            vec.z *= scalar;

            return vec;
        }

        friend Vector3f operator*(float scalar, Vector3f vec) {
            vec.x *= scalar;
            vec.y *= scalar;
            vec.z *= scalar;

            return vec;
        }

        friend Vector3f operator*(const Matrix3x3f& mat, const Vector3f& vec) {
            auto vec1 = mat.getRowVector(0) * vec;
            auto vec2 =  mat.getRowVector(1) * vec;
            auto vec3 =  mat.getRowVector(2) * vec;

            return Vector3f(vec1.x + vec1.y + vec1.z,vec2.x + vec2.y + vec2.z,vec3.x + vec3.y + vec3.z);
        };

#ifdef GLM_CONVERSIONS
        explicit Vector3f(const glm::vec3 glmVec):x(glmVec.x),y(glmVec.y),z(glmVec.z){}
#endif
    };

    struct Vector2f {
        float x = 0.0f, y = 0.0f;

        Vector2f():x(0.0f),y(0.0f){}
        explicit Vector2f(float val):x(val),y(val){}
        explicit Vector2f(Vector3f vec):x(vec.x),y(vec.y){}
        Vector2f(float x, float y):x(x),y(y){}

        friend Vector2f operator+(Vector2f lhs, const Vector2f& rhs) {
            lhs.x += rhs.x;
            lhs.y += rhs.y;

            return lhs;
        }

        friend Vector2f operator-(Vector2f lhs, const Vector2f& rhs) {
            lhs.x -= rhs.x;
            lhs.y -= rhs.y;

            return lhs;
        }

        friend Vector2f operator*(Vector2f lhs, const Vector2f& rhs) {
            lhs.x *= rhs.x;
            lhs.y *= rhs.y;

            return lhs;
        }

        friend Vector2f operator*(float lhs, Vector2f rhs) {
            rhs.x *= lhs;
            rhs.y *= lhs;

            return rhs;
        }

        friend Vector2f operator*(Vector2f lhs, float rhs) {
            lhs.x *= rhs;
            lhs.y *= rhs;

            return lhs;
        }

#ifdef GLM_CONVERSIONS
        explicit Vector2f(const glm::fvec2& glmVec) : x(glmVec.x), y(glmVec.y) {}
        friend glm::vec2 operator=(const Vector2f vec) {
            return glm::vec2(vec.x, vec.y);
        }
#endif
    };
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_VECTOR_H
