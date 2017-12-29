//
// Created by jonas on 12/23/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_CIRCLE_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_CIRCLE_H

#include "shape2d.h"
#include "math/vector_types.h"

namespace Math {
    struct Circle : public Shape2D {
        Circle(const Vector2f& center, float radius):center(center),radius(radius){}

        ShapeType getType() const override {return ShapeType::SHAPE_2D_CIRCLE;}

        Polygon2D toPolygon() const override;
        Bounding2D toBoundingBox() const override;

        Vector2f center;
        float radius;
    };
}


#endif //SERIOUSENGINEFORSERIOUSPEOPLE_CIRCLE_H
