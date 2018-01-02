//
// Created by jonas on 12/24/17.
//

#include <math_include.h>
#include "math/geometry/polygon2d.h"
#include "math/geometry/bounding2d.h"

GG::Polygon2D::Polygon2D(const std::vector<GG::Vector2f> &vertices):
        vertices(vertices)
{
    center = findCenter();
}

GG::Polygon2D GG::Polygon2D::transform(const GG::Matrix3x3f &mat) {
    std::vector<Vector2f> verts = std::vector<Vector2f>();

    verts.reserve(vertices.size());

    for (const auto& vert : vertices) {
        verts.emplace_back(mat * Vector3f(vert.x,vert.y,1.0f));
    }

    return Polygon2D(verts);
}

GG::Polygon2D GG::Polygon2D::toPolygon() const {
    return *this;
}

GG::Bounding2D GG::Polygon2D::toBoundingBox() const {
    float left = 1.0e10f, right = -1.0e10f, top = -1.0e10f, bottom = 1.0e10f;

    for (auto& vert : vertices) {
        left = std::min(left, vert.x);
        right = std::max(right, vert.x);
        top = std::max(top, vert.y);
        bottom = std::max(bottom, vert.y);
    }
    return GG::Bounding2D(left, right, top, bottom);
}

GG::Vector2f GG::Polygon2D::findCenter() {
    Vector2f aggregate = Vector2f(0.0f);
    float totalWeight = 0.0f;

    for(auto& vert : vertices) {
        aggregate = aggregate + (vert/length(vert));
        totalWeight += length(vert);
    }

    aggregate = aggregate / totalWeight;

    return aggregate;
}

const GG::Vector2f &GG::Polygon2D::getCenter() {
    return center;
}
