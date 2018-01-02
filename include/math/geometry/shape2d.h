//
// Created by jonas on 12/23/17.
//

#ifndef GAMEGEOMETRY_SHAPE_H
#define GAMEGEOMETRY_SHAPE_H

namespace GG {
    enum ShapeType {
        SHAPE_2D_AABB,
        SHAPE_2D_CIRCLE,
        SHAPE_2D_POLYGON
    };

    struct Polygon2D;
    struct Bounding2D;
    struct Circle;

    struct Shape2D {
        virtual ShapeType getType()const=0;
        virtual Polygon2D toPolygon()const=0;
        virtual Bounding2D toBoundingBox()const=0;
    };
}


#endif //GAMEGEOMETRY_SHAPE_H
