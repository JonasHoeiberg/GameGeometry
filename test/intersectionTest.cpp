//
// Created by Jonas on 30-12-2017.
//

#include "gtest/gtest.h"
#include "globalTestDefinitions.h"
#include "math/geometry/shapes2d.h"
#include "math/geometry/intersections2d.h"
#include "math_include.h"

using namespace GG;

Polygon2D noIntersectionPolygon = Polygon2D({
    Vector2f(-4.0f, 8.0f),
    Vector2f(-1.0f, 7.0f),
    Vector2f(-3.0f, 5.0f)
});

Polygon2D intersectionPolygon1 = Polygon2D({
    Vector2f(1.0f, 3.0f),
    Vector2f(3.0f, 5.0f),
    Vector2f(6.0f, 3.0f),
    Vector2f(5.0f, 0.0f),
    Vector2f(3.0f, -2.0f)
});

Polygon2D intersectionPolygon2 = Polygon2D({
    Vector2f(5.0f, 6.0f),
    Vector2f(9.0f, 5.0f),
    Vector2f(4.0f, 3.0f)
});

Bounding2D noIntersectionAABB = Bounding2D(
    1.0f,
    4.0f,
    10.0f,
    7.0f
);

Bounding2D intersectionAABB1 = Bounding2D(
    -2.0f,
    2.0f,
    5.0f,
    2.0f
);

Bounding2D intersectionAABB2 = Bounding2D(
    -4.0f,
    -1.0f,
    3.0f,
    1.0f
);

Bounding2D intersectionAABBCircle = Bounding2D(
        1.5f,
        4.0f,
        -3.0f,
        -6.0f
);

Circle noIntersectionCircle = Circle(
        Vector2f(-4.0f, -5.0f),
        3.0f
);

Circle intersectionCircle1 = Circle(
        Vector2f(4.0f, -3.0f),
        2.0f
);

Circle intersectionCircle2 = Circle(
        Vector2f(6.5f, -4.5f),
        1.5f
);

TEST (IntersectionTest, PolygonPolygonIntersection) {
    EXPECT_TRUE(intersect(intersectionPolygon1, intersectionPolygon2));
    EXPECT_FALSE(intersect(noIntersectionPolygon, intersectionPolygon1));
}

TEST (IntersectionTest, PolygonAABBIntersection) {
    EXPECT_TRUE(intersect(intersectionPolygon1, intersectionAABB1));
    EXPECT_FALSE(intersect(noIntersectionPolygon, intersectionAABB1));
}

TEST (IntersectionTest, PolygonCircleIntersection) {
    EXPECT_TRUE(intersect(intersectionPolygon1, intersectionCircle1));
    EXPECT_FALSE(intersect(noIntersectionPolygon, intersectionCircle1));
}

TEST (IntersectionTest, CircleCircleIntersection) {
    EXPECT_TRUE(intersect(intersectionCircle1, intersectionCircle2));
    EXPECT_FALSE(intersect(noIntersectionCircle, intersectionCircle1));
}

TEST (IntersectionTest, CircleAABBIntersection) {
    EXPECT_TRUE(intersect(intersectionCircle1, intersectionAABBCircle));
    EXPECT_FALSE(intersect(noIntersectionCircle, intersectionAABB1));
}

TEST (IntersectionTest, AABBAABBIntersection) {
    EXPECT_TRUE(intersect(intersectionAABB1, intersectionAABB2));
    EXPECT_FALSE(intersect(noIntersectionAABB, intersectionAABB1));
}

TEST (IntersectionTest, ArbitraryShapeIntersection) {
    Shape2D* geometry[9] = {
            &noIntersectionPolygon,
            &noIntersectionAABB,
            &noIntersectionCircle,
            &intersectionAABB2,
            &intersectionAABB1,
            &intersectionPolygon1,
            &intersectionPolygon2,
            &intersectionCircle1,
            &intersectionCircle2
    };

    EXPECT_FALSE(intersect(*geometry[0], *geometry[7]));
    EXPECT_FALSE(intersect(*geometry[4], *geometry[7]));
    EXPECT_FALSE(intersect(*geometry[1], *geometry[2]));
    EXPECT_TRUE(intersect(*geometry[4], *geometry[5]));
    EXPECT_TRUE(intersect(*geometry[7], *geometry[8]));
    EXPECT_TRUE(intersect(*geometry[3], *geometry[4]));
}