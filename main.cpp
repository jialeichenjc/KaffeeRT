#include <iostream>
#include "gtest/gtest.h"

int testFunc() {
    return 2;
}

TEST(testSuite1, test1) {
    EXPECT_EQ(testFunc(), 2);
    std::cout << "Test passed" << std::endl;
}
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