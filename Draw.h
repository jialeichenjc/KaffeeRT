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
        for(int i = 0; i < 600; i++) {
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
void writeToPixel(Canvas &canvas, size_t x, size_t y, const Vec4 &color) {
    assert(x < canvas.width && y < canvas.height);
    canvas.pixels[x][y] = color;
}

Vec4 getColorAtPixel(const Canvas &canvas, size_t x, size_t y) {
    assert(x < canvas.width && y < canvas.height);
    return canvas.pixels[x][y];
}

// 1st line: flavor of PPM used
// 2nd line: width and height in pix
// 3rd line: maximum color value 
void saveCanvasToPPM(const Canvas &canvas, const char* filename) {
    std::cout << "test inside 1" << std::endl;
    std::ofstream fs;
    std::cerr << "Error 1: " << strerror(errno);
    fs.open(filename);
    if(fs.fail()) {
        std::cout << "Failed" << std::endl;
    }
    std::cerr << "Error: " << strerror(errno);
    std::cout << "test inside 2" << std::endl;
    if(!fs.is_open()) {
        std::cout << "Failed to open file" << std::endl;
    }
    std::cout << "test inside 2" << std::endl;
    while(fs.is_open()) {
        fs << "P3\n" << 20 << "\n";
        //std::cout << "test" << std::endl;
        for(int i = 0; i < canvas.height; i++) {
            //std::cout << "test" << std::endl;
            fs << "s\n";
            // for(int j = 0; j < canvas.width; j++) {
            //     fs << "test " << "\n";
            //    // fs << std::to_string(canvas.pixels[i][j]) << " ";
            // }
            // fs << "\n";
        }
        fs.close();
    }
    if(fs.is_open()) {
        fs.close();
    }
}