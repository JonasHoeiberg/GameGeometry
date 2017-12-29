//
// Created by Jonas on 29-12-2017.
//

#include "math/vector_types.h"
#include "gtest/gtest.h"

using namespace Math;

TEST (Vector2fTest, ConstructionAndAssignment) {
    Vector2f vec;

    EXPECT_FLOAT_EQ(vec.x, 0.0f);
    EXPECT_FLOAT_EQ(vec.y, 0.0f);

    vec = Vector2f(4.0f, -4.0f);

    EXPECT_FLOAT_EQ(vec.x, 4.0f);
    EXPECT_FLOAT_EQ(vec.y, -4.0f);
}