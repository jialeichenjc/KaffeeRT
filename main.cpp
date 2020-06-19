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
// */
    Canvas canvas(5,3);
    std::cout << "test" << std::endl;

    Vec4 c1(1.5f, 0, 0);
    Vec4 c2(0, 0.5f, 0);
    Vec4 c3(-0.5f, 0, 1);
//     char* testFile = "output.ppm";
//     saveCanvasToPPM(canvas, testFile);
//     std::cout << "test after" << std::endl;

    std::ofstream fs;
    fs.open("output.txt");
    if(fs.fail()) {
        std::cout << "Failed" << std::endl;
    }
    
    if(fs.is_open()) {
        fs << "P3\n" << 20 << "\n";
        //std::cout << "test" << std::endl;
        for(int i = 0; i < canvas.height; i++) {
            std::cout << "test from the loop" << std::endl;
            // for(int j = 0; j < canvas.width; j++) {
            //   fs << canvas.pixels[i][j].x << " ";
            // }
            fs << "\n";
        }
    }
    if(fs.is_open()) {
        fs.close();
    }

    return 0;
    //return RUN_ALL_TESTS();
}