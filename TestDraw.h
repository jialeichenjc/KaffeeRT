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
    EXPECT_EQ(getColorAtPixel(canvas, 50, 40), color);
}