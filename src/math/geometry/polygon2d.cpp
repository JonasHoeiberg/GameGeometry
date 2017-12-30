//
// Created by jonas on 12/24/17.
//

#include "math/geometry/polygon2d.h"
#include "math/geometry/bounding2d.h"

Math::Polygon2D::Polygon2D(const std::vector<Math::Vector2f> &vertices):
        vertices(vertices)
{
    if (!isConvex()) {
        throw std::exception();
    }
}

Math::Polygon2D Math::Polygon2D::transform(const Math::Matrix3x3f &mat) {
    std::vector<Vector2f> verts = std::vector<Vector2f>();

    verts.reserve(vertices.size());

    for (const auto& vert : vertices) {
        verts.emplace_back(mat * Vector3f(vert.x,vert.y,1.0f));
    }

    return Polygon2D(verts);
}

//TODO: Perform check
bool Math::Polygon2D::isConvex() {
    return true;
}

Math::Polygon2D Math::Polygon2D::toPolygon() const {
    return *this;
}

Math::Bounding2D Math::Polygon2D::toBoundingBox() const {
    float left = 1.0e10f, right = -1.0e10f, top = -1.0e10f, bottom = 1.0e10f;

    for (auto& vert : vertices) {
        left = std::min(left, vert.x);
        right = std::max(right, vert.x);
        top = std::max(top, vert.y);
        bottom = std::max(bottom, vert.y);
    }
    return Math::Bounding2D(left, right, top, bottom);
}
