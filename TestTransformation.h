#pragma once

#include "Mat.h"
#include "gtest/gtest.h"

TEST(TransTests, testTranslation) {
    Mat4 t = translation(5, -3, 2);
    Vec4 p(-3, 4, 5, 1);

    EXPECT_EQ(t * p, Vec4(2, 1, 7, 1));
}