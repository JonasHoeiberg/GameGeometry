//
// Created by Jonas on 30-12-2017.
//

#include "gtest/gtest.h"
#include "globalTestDefinitions.h"
#include "math/geometry/shapes2d.h"

using namespace Math;

TEST (Shape2DTest, Bounding2DTest) {
    Bounding2D aabb = Bounding2D(-1.0f, 1.0f, 1.0f, -1.0f);

    EXPECT_VECTOR2_EQ(aabb.toPolygon()[0],-1.0f, 1.0f);

    EXPECT_AABB_EQ(aabb.toBoundingBox(), -1.0f, 1.0f, 1.0f, -1.0f);
}

TEST (Shape2DTest, CircleTest) {
    Circle circle = Circle(Vector2f(-2.0f, 3.0f),3.0f);

    EXPECT_VECTOR2_EQ(circle.toPolygon()[0], 1.0f, 3.0f);
    EXPECT_VECTOR2_EQ(circle.toPolygon()[90], -2.0f, 6.0f);
    EXPECT_VECTOR2_EQ(circle.toPolygon()[180], -5.0f, 3.0f);
    EXPECT_VECTOR2_EQ(circle.toPolygon()[270], -2.0f, 0.0f);

    EXPECT_AABB_EQ(circle.toBoundingBox(), -5.0f, 1.0f, 6.0f, 0.0f);
}

TEST (Shape2DTest, Polygon2DTest) {
    Polygon2D poly = Polygon2D({
            Vector2f(0.0f, 1.0f),
            Vector2f(1.0f, 0.0f),
            Vector2f(0.0f, 0.0f)
    });

    Vector2f expected[3] = {
            Vector2f(0.0f, 1.0f),
            Vector2f(1.0f, 0.0f),
            Vector2f(0.0f, 0.0f)
    };

    EXPECT_ARRAY_EQUAL(poly, expected, 3);
    EXPECT_ARRAY_EQUAL(poly.toPolygon(), expected, 3);

    //TODO: Transformation
}

TEST (Shape2DTest, ShapeSuperClassTest) {

}