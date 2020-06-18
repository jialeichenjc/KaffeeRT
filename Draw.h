#pragma once

#include "Vec.h"
#include <vector>
#include <assert.h>

class Canvas {
public:
    size_t width, height;
    Vec4** pixels;

    Canvas(size_t i_width, size_t i_height) :
    width(i_width), height(i_height) {
        assert(width > 0 && height > 0);
        pixels = new Vec4[width][height];

    }

    ~Canvas() {
        for(int i = 0; i < height; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

};

// x: width y: height
void writeToPixel(Canvas &canvas, size_t x, size_t y, const Vec4 &color) {

}

Vec4 colorAtPixel(Canvas &canvas, size_t x, size_t y) {
    return Vec4(0, 0, 0);
}
