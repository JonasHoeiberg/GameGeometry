//
// Created by Jonas on 30-12-2017.
//

#include "gtest/gtest.h"
#include "globalTestDefinitions.h"
#include "math/geometry/shapes2d.h"

using namespace GG;

TEST (Shape2DTest, Bounding2DTest) {
    Bounding2D aabb = Bounding2D(-1.0f, 1.0f, 1.0f, -1.0f);

    EXPECT_VECTOR2_EQ(aabb.toPolygon()[0],-1.0f, 1.0f);

    EXPECT_AABB_EQ(aabb.toBoundingBox(), -1.0f, 1.0f, 1.0f, -1.0f);
}

TEST (Shape2DTest, CircleTest) {
    Circle circle = Circle(Vector2f(-2.0f, 3.0f),3.0f);

    EXPECT_VECTOR2_NEAR(circle.toPolygon()[0], 1.0f, 3.0f, 1.0e-6);
    EXPECT_VECTOR2_NEAR(circle.toPolygon()[90], -2.0f, 6.0f, 1.0e-6);
    EXPECT_VECTOR2_NEAR(circle.toPolygon()[180], -5.0f, 3.0f, 1.0e-6);
    EXPECT_VECTOR2_NEAR(circle.toPolygon()[270], -2.0f, 0.0f, 1.0e-6);

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

    EXPECT_FLOAT_EQ(poly.count(), 3);

    auto tPoly = poly.transform(Matrix3x3f({
            2.0f, 0.0f, 0.0f,
            0.0f, 2.0f, 0.0f,
            0.0f, 0.0f, 0.0f
                                           }));

    Vector2f expected2[3] = {
            Vector2f(0.0f, 2.0f),
            Vector2f(2.0f, 0.0f),
            Vector2f(0.0f, 0.0f)
    };

    EXPECT_ARRAY_EQUAL(tPoly, expected2, 3);
}

TEST (Shape2DTest, ShapeSuperClassTest) {
    Shape2D* shape = new Circle(Vector2f(0.0f, 0.0f), 5.0f);

    EXPECT_EQ(shape->getShapeType(), ShapeType2D::SHAPE_2D_CIRCLE);

    EXPECT_FLOAT_EQ(shape->toPolygon().count(),360);

    EXPECT_VECTOR2_NEAR(shape->toPolygon()[0], 5.0f, 0.0f, 10e-6);
    EXPECT_VECTOR2_NEAR(shape->toPolygon()[90], 0.0f, 5.0f, 10e-6);
    EXPECT_VECTOR2_NEAR(shape->toPolygon()[180], -5.0f, 0.0f, 10e-6);
    EXPECT_VECTOR2_NEAR(shape->toPolygon()[270], 0.0f, -5.0f, 10e-6);

    auto circle = dynamic_cast<Circle&>(*shape);

    EXPECT_VECTOR2_EQ(circle.center, 0.0f, 0.0f);
    EXPECT_FLOAT_EQ(circle.radius, 5.0f);
}