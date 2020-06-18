#pragma once

#include "Vec.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(testVec4, testAdd) {
    Vec4 v1(3.0f, 4.0f, 5.0f);
    Vec4 v2(1.0f, 1.0f, 1.0f);
    Vec4 res = v1 + v2;
    EXPECT_EQ(res, Vec4(4.0f, 5.0f, 6.0f));
}

TEST(testVec4, testSub) {
    Vec4 v1(3.0f, 4.0f, 5.0f);
    Vec4 v2(1.0f, 1.0f, 1.0f);
    Vec4 res = v1 - v2;
    EXPECT_EQ(res, Vec4(2.0f, 3.0f, 4.0f));
}

TEST(testVec4, testNegate) {
    Vec4 v1(3.0f, 4.0f, 5.0f);
    EXPECT_EQ(-v1, Vec4(-3.0f, -4.0f, -5.0f));
}

TEST(testVec4, testScalarMult) {
    Vec4 v1(3.0f, 4.0f, 5.0f);
    EXPECT_EQ(v1 * 2, Vec4(6.0f, 8.0f, 10.0f));
    EXPECT_EQ(2 * v1, Vec4(6.0f, 8.0f, 10.0f));
}

TEST(testVec4, testScalarDiv) {
    Vec4 v1(3.0f, 4.0f, 5.0f);
    EXPECT_EQ(v1 / 2, Vec4(1.5f, 2.0f, 2.5f));
}

TEST(testVec4, testMag) {
    Vec4 v1(1.0f, 2.0f, 3.0f);
    EXPECT_FLOAT_EQ(mag(v1), (float)sqrt(14));
}

TEST(testVec4, testNorm) {
    Vec4 v1(1.0f, 2.0f, 3.0f);
    Vec4 res = norm(v1);
    EXPECT_FLOAT_EQ(res.x, 1.0f/mag(v1));
    EXPECT_FLOAT_EQ(res.y, 2.0f/mag(v1));
    EXPECT_FLOAT_EQ(res.z, 3.0f/mag(v1));
    EXPECT_FLOAT_EQ(mag(res), 1.0f);
}

TEST(testVec4, testDot) {
    Vec4 v1(1, 2, 3);
    Vec4 v2(2, 3, 4);
    EXPECT_FLOAT_EQ(dot(v1, v2), 20);
}

TEST(testVec4, testCross) {
    Vec4 v1(1, 2, 3);
    Vec4 v2(2, 3, 4);
    EXPECT_EQ(cross(v1, v2), Vec4(-1, 2, -1));
    EXPECT_EQ(cross(v2, v1), Vec4(1, -2, 1));
}

TEST(testVec4, hadamardProd) {
    Vec4 v1(1, 0.2f, 0.4f);
    Vec4 v2(0.9f, 1, 0.1f);
    EXPECT_EQ(hadamardProd(v1, v2), Vec4(0.9f, 0.2f, 0.04f));
}