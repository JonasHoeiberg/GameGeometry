//
// Created by Jonas on 29-12-2017.
//

#include "math/vector_types.h"
#include "gtest/gtest.h"

#include "globalTestDefinitions.h"

using namespace Math;

TEST (VectorTest, ConstructionAndAssignment) {
    Vector2f vec;

    EXPECT_VECTOR2_EQ(vec, 0.0f, 0.0f);

    vec = Vector2f(4.0f, -4.0f);

    EXPECT_VECTOR2_EQ(vec, 4.0f, -4.0f);

    Vector3f vec2;

    EXPECT_VECTOR3_EQ(vec2, 0.0f, 0.0f, 0.0f);

    vec2 = Vector3f(4.0f, -4.0f, 1.0f);

    EXPECT_VECTOR3_EQ(vec2, 4.0f, -4.0f, 1.0f);
}

TEST (VectorTest, Vector3fCastTo2f) {
    Vector2f vec = Vector2f(Vector3f(1.0f, 2.0f, -10.0f));

    EXPECT_VECTOR2_EQ(vec, 1.0f, 2.0f);
}

TEST (VectorTest, PlusOperatorTest) {
    Vector2f vec = Vector2f(2.0f, 2.0f) + Vector2f(1.0f, 3.0f);

    EXPECT_VECTOR2_EQ(vec, 3.0f, 5.0f);

    Vector3f vec2 = Vector3f(1.0f, -1.0f, 0.0f) + Vector3f(2.0f, 4.0f, 1.0f);

    EXPECT_VECTOR3_EQ(vec2, 3.0f, 3.0f, 1.0f);
}

TEST (VectorTest, SubtractionOperatorTest) {
    Vector2f vec = Vector2f(2.0f, 2.0f) - Vector2f(1.0f, 3.0f);

    EXPECT_VECTOR2_EQ(vec, 1.0f, -1.0f);

    Vector3f vec2 = Vector3f(1.0f, -1.0f, 0.0f) - Vector3f(2.0f, 4.0f, 1.0f);

    EXPECT_VECTOR3_EQ(vec2, -1.0f, -5.0f, -1.0f);
}

TEST (VectorTest, MultiplicationOperatorTest) {
    Vector2f vec = Vector2f(2.0f, 2.0f) * Vector2f(1.0f, 3.0f);

    EXPECT_VECTOR2_EQ(vec, 2.0f, 6.0f);

    Vector3f vec2 = Vector3f(1.0f, -1.0f, 0.0f) * Vector3f(2.0f, 4.0f, 1.0f);

    EXPECT_VECTOR3_EQ(vec2, 2.0f, -4.0f, 0.0f);
}