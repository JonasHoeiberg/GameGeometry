//
// Created by jonas on 12/23/17.
//

#ifndef GAMEGEOMETRY_SHAPE_H
#define GAMEGEOMETRY_SHAPE_H

#include "math/geometry/geometry2d.h"

namespace GG {
    enum ShapeType2D {
        SHAPE_2D_AABB,
        SHAPE_2D_CIRCLE,
        SHAPE_2D_POLYGON
    };

    struct Polygon2D;
    struct Bounding2D;
    struct Circle;

    struct Shape2D : public Geometry2D {
        virtual ShapeType2D getShapeType()const=0;
        virtual Polygon2D toPolygon()const=0;
        virtual Bounding2D toBoundingBox()const=0;
        GeometryType2D getGeometryType() const override {
            return GeometryType2D::GEOMETRY_2D_SHAPE;
        }
    };
}


#endif //GAMEGEOMETRY_SHAPE_H
