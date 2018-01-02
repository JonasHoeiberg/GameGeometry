//
// Created by jonas on 12/23/17.
//

#ifndef GAMEGEOMETRY_BOUNDING2D_H
#define GAMEGEOMETRY_BOUNDING2D_H

#include "shape2d.h"

namespace GG {
    struct Bounding2D : Shape2D {
        Bounding2D(float left, float right, float top, float bottom) {
            this->left = left;
            this->right = right;
            this->top = top;
            this->bottom = bottom;
        }

        float left;
        float right;
        float top;
        float bottom;

        ShapeType getType() const override {
            return ShapeType::SHAPE_2D_AABB;
        }

        Polygon2D toPolygon() const override;
        Bounding2D toBoundingBox() const override;
    };
}


#endif //GAMEGEOMETRY_BOUNDING2D_H
