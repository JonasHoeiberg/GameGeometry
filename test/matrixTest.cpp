//
// Created by Jonas on 30-12-2017.
//

#include "globalTestDefinitions.h"
#include "math_include.h"
#include "gtest/gtest.h"

using namespace Math;

TEST (MatrixTest, ConstructorAndAssignment) {
    Matrix3x3f mat;

    float expected[9] = {   1.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 1.0f};

    EXPECT_MATRIX3_EQ(mat, expected);

    Matrix3x3f mat2 = Matrix3x3f({2.0f, 2.0f, 2.0f,
                                  2.0f, 2.0f, 2.0f,
                                  2.0f, 2.0f, 2.0f
                                 });

    float expected2[9] = {2.0f, 2.0f, 2.0f,
                          2.0f, 2.0f, 2.0f,
                          2.0f, 2.0f, 2.0f};

    EXPECT_MATRIX3_EQ(mat2, expected2);

    mat = Matrix3x3f(mat2);

    EXPECT_MATRIX3_EQ(mat, expected2)

    mat[2] = 3.0f;

    EXPECT_MATRIX3_EQ(mat2, expected2);

    expected2[2] = 3.0f;

    EXPECT_MATRIX3_EQ(mat, expected2);

    mat2 = mat;

    EXPECT_MATRIX3_EQ(mat2, expected2);
}

TEST (MatrixTest, VectorAccessors) {
    Matrix3x3f mat = Matrix3x3f({ 1.0f, 2.0f, 3.0f,
                                  4.0f, 5.0f, 6.0f,
                                  7.0f, 8.0f, 9.0f
                                });

    EXPECT_VECTOR3_EQ(mat.getColumnVector(1), 2.0f, 5.0f, 8.0f);
    EXPECT_VECTOR3_EQ(mat.getRowVector(2),7.0f, 8.0f, 9.0f);
}

TEST (MatrixTest, MultiplicationTest) {
    Matrix3x3f mat = Matrix3x3f({ 1.0f, 2.0f, 3.0f,
                                  4.0f, 5.0f, 6.0f,
                                  7.0f, 8.0f, 9.0f
                                });

    Vector3f vec = Vector3f(1.0f, 1.0f, 1.0f);

    auto result = mat * vec;

    EXPECT_VECTOR3_EQ(result, 6.0f, 15.0f, 24.0f);

    Matrix3x3f mat2 = Matrix3x3f({ 9.0f, 8.0f, 7.0f,
                                   6.0f, 5.0f, 4.0f,
                                   3.0f, 2.0f, 1.0f});

    auto resultMat = mat * mat2;

    float expectedResult[9] = { 30.0f, 24.0f, 18.0f,
                            84.0f, 69.0f, 54.0f,
                            138.0f, 114.0f, 90.0f};

    EXPECT_MATRIX3_EQ(resultMat,expectedResult);
}