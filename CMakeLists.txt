cmake_minimum_required(VERSION 3.8)
project(GameGeometry)

set_property(TARGET PROPERTY CXX_STANDARD 17)

set(GG_COMPILE_TESTS 1)

if (GG_MAKE_GLM_CONVERSIONS)
    include_directories(lib/glm/)
    add_definitions(-DGLM_CONVERSIONS)
endif()

if (MINGW)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif()

include_directories(include)

set(SOURCE_FILES
        src/math/vector_types.cpp
        src/math/matrix_types.cpp
        src/math/geometry/shape2d.cpp
        src/math/geometry/bounding2d.cpp
        src/math/geometry/circle.cpp
        src/math/geometry/polygon2d.cpp
        src/math/math_util.cpp
        src/math/geometry/intersections2d.cpp
        src/math/geometry/geometry_util.cpp
        src/math/geometry/geometry2d.cpp)

add_library(GameGeometry ${SOURCE_FILES})

if (GG_COMPILE_TESTS)
    file(GLOB GG_TEST_SOURCE_FILES test/*.cpp)

    add_executable(GameGeometryTest ${GG_TEST_SOURCE_FILES})

    add_subdirectory(lib/googletest)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})
    target_link_libraries(GameGeometryTest gtest gmock gtest_main)
    target_link_libraries(GameGeometryTest GameGeometry)
endif()