#pragma once

#define _USE_MATH_DEFINES

#include "Mat.h"
#include "Transformation.h"
#include "gtest/gtest.h"
#include <math.h>

TEST(TransTests, testTranslation) {
    Mat4 t = translation(5, -3, 2);
    Vec4 p(-3, 4, 5, 1);

    EXPECT_EQ(t * p, Vec4(2, 1, 7, 1));

    Mat4 inv = inverse(t);
    EXPECT_EQ(inv * p, Vec4(-8, 7, 3, 1));

    Vec4 v(-3, 4, 5);
    EXPECT_EQ(t * v, v);
}

TEST(TransTests, testScaling) {
    Mat4 t = scaling(2, 3, 4);
    Vec4 v(-4, 6, 8);
    EXPECT_EQ(t * v, Vec4(-8, 18, 32));

    Mat4 inv = inverse(t);
    EXPECT_EQ(inv * v, Vec4(-2, 2, 2));

    // Reflection is scaling by a negative value
    t = scaling(-1, 1, 1);
    Vec4 p(2, 3, 4, 1);
    EXPECT_EQ(t * p, Vec4(-2, 3, 4, 1));
}

TEST(TransTests, testRotateX) {
    Vec4 p(0, 1, 0, 1);
    Mat4 half_quarter = rotationX((float)M_PI/4);
    Mat4 full_quarter = rotationX((float)M_PI/2);
    EXPECT_EQ(half_quarter * p, Vec4(0, (float)sqrt(2)/2, (float)sqrt(2)/2));
    EXPECT_EQ(full_quarter * p, Vec4(0, 0, 1));

    // Test inverse of rotation
    Mat4 inv = inverse(half_quarter);
    EXPECT_EQ(inv * p, Vec4(0, (float)sqrt(2)/2, -(float)sqrt(2)/2));
}

TEST(TransTests, testRotateY) {
    Vec4 p(0, 0, 1, 1);
    Mat4 half_quarter = rotationY((float)M_PI/4);
    Mat4 full_quarter = rotationY((float)M_PI/2);
    EXPECT_EQ(half_quarter * p, Vec4((float)sqrt(2)/2, 0, (float)sqrt(2)/2));
    EXPECT_EQ(full_quarter * p, Vec4(1, 0, 0));
}

TEST(TransTests, testRotateZ) {
    Vec4 p(0, 1, 0, 1);
    Mat4 half_quarter = rotationZ((float)M_PI/4);
    Mat4 full_quarter = rotationZ((float)M_PI/2);
    EXPECT_EQ(half_quarter * p, Vec4(-(float)sqrt(2)/2, (float)sqrt(2)/2, 0));
    EXPECT_EQ(full_quarter * p, Vec4(-1, 0, 0));
}

TEST(TransTests, testShearing) {
    // Moves x in proportion to y
    Mat4 t = shearing(1, 0, 0, 0, 0, 0);
    Vec4 p(2, 3, 4, 1);
    EXPECT_EQ(t * p, Vec4(5, 3, 4, 1));

    // Moves x in proportion to z
    t = shearing(0, 1, 0, 0, 0, 0);
    EXPECT_EQ(t * p, Vec4(6, 3, 4, 1));

    // Moves y in proportion to x
    t = shearing(0, 0, 1, 0, 0, 0);
    EXPECT_EQ(t * p, Vec4(2, 5, 4, 1));

    // Moves y in proportion to z
    t = shearing(0, 0, 0, 1, 0, 0);
    EXPECT_EQ(t * p, Vec4(2, 7, 4, 1));

     // Moves z in proportion to x
    t = shearing(0, 0, 0, 0, 1, 0);
    EXPECT_EQ(t * p, Vec4(2, 3, 6, 1));

     // Moves z in proportion to y
    t = shearing(0, 0, 0, 0, 0, 1);
    EXPECT_EQ(t * p, Vec4(2, 3, 7, 1));
}