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
    }

    Canvas() {
        pixels = new Vec4*[600];
        for(int i = 0; i < 600; i++) {
            pixels[i] = new Vec4[800];
        }
        width = 800;
        height = 600;
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
    assert(x < canvas.width && y < canvas.height);
    canvas.pixels[x][y] = color;
}

Vec4 getColorAtPixel(Canvas &canvas, size_t x, size_t y) {
    assert(x < canvas.width && y < canvas.height);
    return canvas.pixels[x][y];
}
