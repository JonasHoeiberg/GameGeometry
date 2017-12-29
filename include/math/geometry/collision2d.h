//
// Created by jonas on 12/29/17.
//

#ifndef SERIOUSENGINEFORSERIOUSPEOPLE_COLLISION_H
#define SERIOUSENGINEFORSERIOUSPEOPLE_COLLISION_H

#include "shapes2d.h"

namespace Math {
    bool overlap(const Polygon2D &poly1, const Polygon2D &poly2);
    bool overlap(const Polygon2D& poly, const Circle& circle);
    bool overlap(const Polygon2D& poly, const Bounding2D& aabb);

    bool overlap(const Bounding2D& aabb, const Polygon2D& poly);
    bool overlap(const Bounding2D& aabb, const Circle& circle);
    bool overlap(const Bounding2D& aabb1, const Bounding2D& aabb2);

    bool overlap(const Circle& circle, const Polygon2D& poly);
    bool overlap(const Circle& circle1, const Circle& circle2);
    bool overlap(const Circle& circle, const Bounding2D& aabb);

    template<class T>
    bool overlap(const T& shape1, const Shape2D& shape2);

    template<class T>
    bool overlap(const Shape2D& shape2, const T& shape1);

    bool overlap(const Shape2D& shape1, const Shape2D& shape2);
}


#endif //SERIOUSENGINEFORSERIOUSPEOPLE_COLLISION_H
