#include "vec.h"
#include "gtest/gtest.h"
#include <iostream>

TEST(testVec4, testAdd) {
    vec4 v1(3.0f, 4.0f, 5.0f);
    vec4 v2(1.0f, 1.0f, 1.0f);
    vec4 res = v1 + v2;
    EXPECT_EQ(res, vec4(4.0f, 5.0f, 6.0f));
}

TEST(testVec4, testSub) {
    vec4 v1(3.0f, 4.0f, 5.0f);
    vec4 v2(1.0f, 1.0f, 1.0f);
    vec4 res = v1 - v2;
    EXPECT_EQ(res, vec4(2.0f, 3.0f, 4.0f));
}
