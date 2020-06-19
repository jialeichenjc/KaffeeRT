#pragma once

#include "gtest/gtest.h"
#include "Draw.h"

TEST(DrawTests, testCreateCanvas) {
    Canvas canvas;
    Vec4 color = getColorAtPixel(canvas, 250, 300);
    EXPECT_EQ(canvas.width, 800);
    EXPECT_EQ(canvas.height, 600);
    EXPECT_EQ(color, Vec4(0.0f, 0.0f, 0.0f));
}

TEST(DrawTests, testDrawCanvas) {
    Canvas canvas;
    Vec4 color(100, 150, 200); // create a test color
    writeToPixel(canvas, 50, 40, color);
    EXPECT_EQ(getColorAtPixel(canvas, 50, 40), clampVec(color));
}

TEST(DrawTests, testSaveCanvas) {
    Canvas canvas(5,3);

    Vec4 c1(1.5f, 0, 0);
    Vec4 c2(0, 0.5f, 0);
    Vec4 c3(-0.5f, 0, 1);
    char* testFile = "output.ppm";

    writeToPixel(canvas, 0, 0, c1);
    writeToPixel(canvas, 2, 1, c2);
    writeToPixel(canvas, 4, 2, c3);

    saveCanvasToPPM(canvas, testFile);

}