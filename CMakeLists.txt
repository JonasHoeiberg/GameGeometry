cmake_minimum_required(VERSION 3.6)
project(GameGeometry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DGLM_FORCE_SWIZZLE)

include_directories(lib/glm/)
include_directories(include)

set(SOURCE_FILES
        src/math/vector_types.cpp
        src/math/matrix_types.cpp
        src/math/geometry/shape2d.cpp
        src/math/geometry/bounding2d.cpp
        src/math/geometry/circle.cpp
        src/math/geometry/polygon2d.cpp
        src/math/math_util.cpp
        src/math/geometry/collision2d.cpp)

add_library(GameGeometry ${SOURCE_FILES})