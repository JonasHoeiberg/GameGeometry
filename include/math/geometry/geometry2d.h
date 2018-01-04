//
// Created by Jonas on 02-01-2018.
//

#ifndef GAMEGEOMETRY_GEOMETRY2D_H
#define GAMEGEOMETRY_GEOMETRY2D_H

namespace GG {
    enum GeometryType2D {
        GEOMETRY_2D_SHAPE,
        GEOMETRY_2D_LINE,
        GEOMETRY_2D_LINE_SEGMENT
    };

    struct Geometry2D {
        virtual GeometryType2D getGeometryType() const=0;
    };
}


#endif //GAMEGEOMETRY_GEOMETRY2D_H
