#pragma once

#include "Mat.h"
#include "gtest/gtest.h"

TEST(TransTests, testTranslation) {
    Mat4 t = translation(5, -3, 2);
    Vec4 p(-3, 4, 5, 1);

    EXPECT_EQ(t * p, Vec4(2, 1, 7, 1));

    Mat4 inv = inverse(t);
    EXPECT_EQ(inv * p, Vec4(-8, 7, 3, 1));

    Vec4 v(-3, 4, 5);
    EXPECT_EQ(t * v, v);
}

