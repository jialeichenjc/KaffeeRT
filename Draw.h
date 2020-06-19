#pragma once

#include "Vec.h"
#include <vector>
#include <assert.h>
#include <iostream>
#include <fstream>

class Canvas {
public:
    size_t width, height;
    Vec4** pixels;

    Canvas(size_t i_width = 800, size_t i_height = 600) {
        width = i_width;
        height = i_height;
        assert(width > 0 && height > 0);
        pixels = new Vec4*[height];
        for(int i = 0; i < height; i++) {
            pixels[i] = new Vec4[width];
        }
        
    }

    ~Canvas() {
        for(int i = 0; i < height; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

};

// x: width y: height
void writeToPixel(Canvas &canvas, size_t col, size_t row, const Vec4 &color) {
    assert(col < canvas.width && row < canvas.height);
    canvas.pixels[row][col] = clampVec(color);
}

Vec4 getColorAtPixel(const Canvas &canvas, size_t col, size_t row) {
    assert(col < canvas.width && row < canvas.height);
    return canvas.pixels[row][col];
}

// 1st line: flavor of PPM used
// 2nd line: width and height in pix
// 3rd line: maximum color value 
void saveCanvasToPPM(const Canvas &canvas, const char* filename) {
    std::ofstream fs(filename);
    if(fs.fail()) {
        std::cout << "Failed" << std::endl;
    }
    if (fs.is_open()) {
        fs << "P3\n" << canvas.width << " " << canvas.height << "\n";
        for(int i = 0; i < canvas.height; i++) {
            for(int j = 0; j < canvas.width; j++) {
               fs << canvas.pixels[i][j].x << " " << canvas.pixels[i][j].y << " " << canvas.pixels[i][j].z << " ";
            }
            fs << "\n";
        }
    }
    
}