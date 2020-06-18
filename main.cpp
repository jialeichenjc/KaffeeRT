#include <iostream>
#include "gtest/gtest.h"
#include "TestVec4.h"
#include "TestDraw.h"

int main(int argc, char **argv) {
    std::cout << "Hello world!!" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
/*
TEST(TestSuiteName, TestName) {
  ... test body ...
}
*/
    return RUN_ALL_TESTS();
}