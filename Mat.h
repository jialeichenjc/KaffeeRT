#pragma once
#include <iostream>

#include "math.h"
#include "Vec.h"

// 4 x 4 matrix
class Mat4 {
public:
    float data[4][4];
    Mat4() {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                data[i][j] = 0;
            }
        }
    }
    // row major order
    Mat4(float a00, float a01, float a02, float a03,
         float a10, float a11, float a12, float a13,
         float a20, float a21, float a22, float a23,
         float a30, float a31, float a32, float a33) {
        
        data[0][0] = a00;
        data[0][1] = a01;
        data[0][2] = a02;
        data[0][3] = a03;
        data[1][0] = a10;
        data[1][1] = a11;
        data[1][2] = a12;
        data[1][3] = a13;
        data[2][0] = a20;
        data[2][1] = a21;
        data[2][2] = a22;
        data[2][3] = a23;
        data[3][0] = a30;
        data[3][1] = a31;
        data[3][2] = a32;
        data[3][3] = a33;
    }
};

class Mat3 {
public:
    float data[3][3];
    Mat3() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                data[i][j] = 0;
            }
        }
    }

    // row major order
    Mat3(float a00, float a01, float a02, 
         float a10, float a11, float a12, 
         float a20, float a21, float a22) {
        
        data[0][0] = a00;
        data[0][1] = a01;
        data[0][2] = a02;
        data[1][0] = a10;
        data[1][1] = a11;
        data[1][2] = a12;
        data[2][0] = a20;
        data[2][1] = a21;
        data[2][2] = a22;
    }    
    
};

class Mat2 {
public:
    float data[2][2];
    Mat2() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                data[i][j] = 0;
            }
        }
    }
    // row major order
    Mat2(float a00, float a01,
         float a10, float a11) {

        data[0][0] = a00;
        data[0][1] = a01;
        data[1][0] = a10;
        data[1][1] = a11;
    }    
    
};

static Mat4 IDENTITY_MATRIX = Mat4(
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
);

inline bool operator==(const Mat4 &m1, const Mat4 &m2) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(!FloatEqual(m1.data[i][j], m2.data[i][j])) { return false; }
        }
    }
    return true;
}

inline bool operator!=(const Mat4 &m1, const Mat4 &m2) {
    return !(m1 == m2);
}

inline bool operator==(const Mat3 &m1, const Mat3 &m2) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(!FloatEqual(m1.data[i][j], m2.data[i][j])) { return false; }
        }
    }

    return true;
}

inline bool operator!=(const Mat3 &m1, const Mat3 &m2) {
    return !(m1 == m2);
}

inline bool operator==(const Mat2 &m1, const Mat2 &m2) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(!FloatEqual(m1.data[i][j], m2.data[i][j])) { return false; }
        }
    }
    return true;
}

inline Mat4 operator*(const Mat4 &m1, const Mat4 &m2) {
    Mat4 res;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            float sum = 0;
            for(int id = 0; id < 4; id++) {
                sum += m1.data[i][id] * m2.data[id][j];
            }          
            res.data[i][j] = sum;
        }
    }

    return res;

    // return Mat4(
    //     m1.data[0][0] * m2.data[0][0] + m1.data[0][1] * m2.data[1][0] + m1.data[0][2] * m2.data[2][0] + m1.data[0][3] * m2.data[3][0], // row 0 col 0
    //     m1.data[0][0] * m2.data[0][1] + m1.data[0][1] * m2.data[1][1] + m1.data[0][2] * m2.data[2][1] + m1.data[0][3] * m2.data[3][1], // row 0 col 1
    //     m1.data[0][0] * m2.data[0][2] + m1.data[0][1] * m2.data[1][2] + m1.data[0][2] * m2.data[2][2] + m1.data[0][3] * m2.data[3][2], // row 0 col 2
    //     m1.data[0][0] * m2.data[0][3] + m1.data[0][1] * m2.data[1][3] + m1.data[0][2] * m2.data[2][3] + m1.data[0][3] * m2.data[3][3], // row 0 col 3

    //     m1.data[1][0] * m2.data[0][0] + m1.data[1][1] * m2.data[1][0] + m1.data[1][2] * m2.data[2][0] + m1.data[1][3] * m2.data[3][0], // row 1 col 0
    //     m1.data[1][0] * m2.data[0][1] + m1.data[1][1] * m2.data[1][1] + m1.data[1][2] * m2.data[2][1] + m1.data[1][3] * m2.data[3][1], // row 1 col 1
    //     m1.data[1][0] * m2.data[0][2] + m1.data[1][1] * m2.data[1][2] + m1.data[1][2] * m2.data[2][2] + m1.data[1][3] * m2.data[3][2], // row 1 col 2
    //     m1.data[1][0] * m2.data[0][3] + m1.data[1][1] * m2.data[1][3] + m1.data[1][2] * m2.data[2][3] + m1.data[1][3] * m2.data[3][3], // row 1 col 3

    //     m1.data[2][0] * m2.data[0][0] + m1.data[2][1] * m2.data[1][0] + m1.data[2][2] * m2.data[2][0] + m1.data[2][3] * m2.data[3][0], // row 2 col 0
    //     m1.data[2][0] * m2.data[0][1] + m1.data[2][1] * m2.data[1][1] + m1.data[2][2] * m2.data[2][1] + m1.data[2][3] * m2.data[3][1], // row 2 col 1
    //     m1.data[2][0] * m2.data[0][2] + m1.data[2][1] * m2.data[1][2] + m1.data[2][2] * m2.data[2][2] + m1.data[2][3] * m2.data[3][2], // row 2 col 2
    //     m1.data[2][0] * m2.data[0][3] + m1.data[2][1] * m2.data[1][3] + m1.data[2][2] * m2.data[2][3] + m1.data[2][3] * m2.data[3][3], // row 2 col 3

    //     m1.data[3][0] * m2.data[0][0] + m1.data[3][1] * m2.data[1][0] + m1.data[3][2] * m2.data[2][0] + m1.data[3][3] * m2.data[3][0], // row 3 col 0
    //     m1.data[3][0] * m2.data[0][1] + m1.data[3][1] * m2.data[1][1] + m1.data[3][2] * m2.data[2][1] + m1.data[3][3] * m2.data[3][1], // row 3 col 1
    //     m1.data[3][0] * m2.data[0][2] + m1.data[3][1] * m2.data[1][2] + m1.data[3][2] * m2.data[2][2] + m1.data[3][3] * m2.data[3][2], // row 3 col 2
    //     m1.data[3][0] * m2.data[0][3] + m1.data[3][1] * m2.data[1][3] + m1.data[3][2] * m2.data[2][3] + m1.data[3][3] * m2.data[3][3] // row 3 col 3

    // );
}

inline Vec4 operator*(const Mat4 &m, const Vec4 &v) {
    return Vec4(
        m.data[0][0] * v.x + m.data[0][1] * v.y + m.data[0][2] * v.z + m.data[0][3] * v.w,
        m.data[1][0] * v.x + m.data[1][1] * v.y + m.data[1][2] * v.z + m.data[1][3] * v.w,
        m.data[2][0] * v.x + m.data[2][1] * v.y + m.data[2][2] * v.z + m.data[2][3] * v.w,
        m.data[3][0] * v.x + m.data[3][1] * v.y + m.data[3][2] * v.z + m.data[3][3] * v.w
    );
}

inline Mat4 transpose(const Mat4 &m) {
    return Mat4(
        m.data[0][0], m.data[1][0], m.data[2][0], m.data[3][0],
        m.data[0][1], m.data[1][1], m.data[2][1], m.data[3][1],
        m.data[0][2], m.data[1][2], m.data[2][2], m.data[3][2],
        m.data[0][3], m.data[1][3], m.data[2][3], m.data[3][3]
    );
}

// returns a copy of the given matrix with the given row and column removed
inline Mat3 submatrix(const Mat4 &m, int row, int col) {
    Mat3 res;
    for(int i = 0; i < 4; i++) {
        int x = i;
        if(i == row) { continue; }
        if(i > row) { --x; }
        for(int j = 0; j < 4; j++) {
            int y = j;
            if(j == col) { continue; }
            if(j > col) { --y; }
            res.data[x][y] = m.data[i][j];
        }
    }
    return res;
}

inline Mat2 submatrix(const Mat3 &m, int row, int col) {
    Mat2 res;
    for(int i = 0; i < 3; i++) {
        int x = i;
        if(i == row) { continue; }
        if(i > row) { --x; }
        for(int j = 0; j < 4; j++) {
            int y = j;
            if(j == col) { continue; }
            if(j > col) { --y; }
            res.data[x][y] = m.data[i][j];
        }
    }
    return res;
}

inline float det(const Mat2 &m) {
    return m.data[0][0] * m.data[1][1] - m.data[0][1] * m.data[1][0];
}

inline float minor(const Mat3 &m, int row, int col) {
    Mat2 sub = submatrix(m, row, col);
    return det(sub);
}

inline float cofactor(const Mat3 &m, int row, int col) {
    return minor(m, row, col) * (float)pow(-1, row + col);
}


inline float det(const Mat3 &m) {
    float sum = 0;
    // use the first row
    for(int i = 0; i < 3; i++) {
        sum += m.data[0][i] * cofactor(m, 0, i);
    }
    return sum;
}

inline float minor(const Mat4 &m, int row, int col) {
    Mat3 sub = submatrix(m, row, col);
    return det(sub);
}

inline float cofactor(const Mat4 &m, int row, int col) {
    return minor(m, row, col) * (float)pow(-1, row + col);
}

inline float det(const Mat4 &m) {
    float sum = 0;
    // use the first row
    for(int i = 0; i < 4; i++) {
        sum += m.data[0][i] * cofactor(m, 0, i);
    }
    return sum;
}

inline bool isInvertible(const Mat4 &m) {
    if(det(m) == 0) {
        return false;
    }

    return true;
}

inline Mat4 inverse(const Mat4 &m) {
    // create matrix of cofactors
    Mat4 coMat;
    Mat4 tMat;
    Mat4 res;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            coMat.data[i][j] = cofactor(m, i, j);
        }
    }
    tMat = transpose(coMat);
    float determinant = det(m);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
           res.data[i][j] = tMat.data[i][j] / determinant;
        }
    }
    return res;
}

inline Mat4 translation(float x, float y, float z) {

}

void printMat(const Mat4 &m) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            std::cout << m.data[i][j] << " ";
        }
        std::cout <<std::endl;
    }
}