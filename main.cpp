#include <iostream>
#include "AddTests.h"

int main(int argc, char **argv) {
    std::cout << "Hello world!!" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}