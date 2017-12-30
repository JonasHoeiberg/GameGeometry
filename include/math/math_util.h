//
// Created by jonas on 12/29/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H

namespace Math {
    struct Vector2f;
    struct Vector3f;

    float cos(float rad);

    float sin(float rad);

    float dot(const Vector2f& vec1, const Vector2f& vec2);

    float dot(const Vector3f& vec1, const Vector3f& vec2);
}

#endif //SERIOUSENGINEFORSERIOUSPEOPLE_TRIG_FUNCTIONS_H
