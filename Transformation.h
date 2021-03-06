#pragma once
#include <cmath>
#include "Mat.h"

/*
    Rotation here is left-handed
*/

// Rotate around x axis, angle r in radians
inline Mat4 rotationX(float r) {
    return Mat4(
        1, 0, 0, 0,
        0, cos(r), -sin(r), 0,
        0, sin(r), cos(r), 0,
        0, 0, 0, 1
    );
}

// Rotate around y axis, angle r in radians
inline Mat4 rotationY(float r) {
    return Mat4(
        cos(r), 0, sin(r), 0,
        0, 1, 0, 0,
        -sin(r), 0, cos(r), 0,
        0, 0, 0, 1
    );
}

// Rotate around z axis, angle r in radians
inline Mat4 rotationZ(float r) {
    return Mat4(
        cos(r), -sin(r), 0, 0,
        sin(r), cos(r), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

// Shearing
inline Mat4 shearing(float xy, float xz, float yx, float yz, float zx, float zy) {
    return Mat4(
        1, xy, xz, 0,
        yx, 1, yz, 0,
        zx, zy, 1, 0,
        0, 0, 0, 1
    );
}
