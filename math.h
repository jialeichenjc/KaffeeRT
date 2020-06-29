#pragma once
#define EPSILON 0.00001f

#include <cmath>

bool FloatEqual(float a, float b) {
    return abs(a - b) < EPSILON;
}
