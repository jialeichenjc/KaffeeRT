#pragma once

#include "Mat.h"
#include "gtest/gtest.h"

TEST(MatTests, TestMat4Creation) {
    Mat4 mat;
    EXPECT_FLOAT_EQ(mat.data[0][0], 0.0f);
    EXPECT_FLOAT_EQ(mat.data[2][1], 0.0f);
    EXPECT_FLOAT_EQ(mat.data[3][2], 0.0f);
    EXPECT_FLOAT_EQ(mat.data[3][3], 0.0f);

    Mat4 mat1(
        1, 2, 3, 4,
        5.5f, 6.5f, 7.5f, 8.5f,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );
    EXPECT_FLOAT_EQ(mat1.data[0][0], 1);
    EXPECT_FLOAT_EQ(mat1.data[0][3], 4);
    EXPECT_FLOAT_EQ(mat1.data[1][0], 5.5f);
    EXPECT_FLOAT_EQ(mat1.data[1][2], 7.5f);
    EXPECT_FLOAT_EQ(mat1.data[2][2], 11);
    EXPECT_FLOAT_EQ(mat1.data[3][0], 13.5);
    EXPECT_FLOAT_EQ(mat1.data[3][2], 15.5);

}

TEST(MatTests, TestMat3Creation) {
    Mat3 m(
        -3, 5, 0,
        1, -2, -7,
        0, 1, 1
    );

    EXPECT_FLOAT_EQ(m.data[0][0], -3);
    EXPECT_FLOAT_EQ(m.data[1][1], -2);
    EXPECT_FLOAT_EQ(m.data[2][2], 1);
}

TEST(MatTests, TestMat2Creation) {
    Mat2 m(
        -3, 5,
        1, -2
    );

    EXPECT_FLOAT_EQ(m.data[0][0], -3);
    EXPECT_FLOAT_EQ(m.data[0][1], 5);
    EXPECT_FLOAT_EQ(m.data[1][0], 1);
    EXPECT_FLOAT_EQ(m.data[1][1], -2);
}

TEST(MatTests, TestMatComp) {
    Mat4 mat1(
        1, 2, 3, 4,
        5.5f, 6.5f, 7.5f, 8.5f,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );

    Mat4 mat2(
        1, 2, 3, 4,
        5.5f, 6.5f, 7.5f, 8.5f,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );

    Mat4 mat3(
        1, 2, 3, 4,
        5, 6.5f, 7.5f, 8.5f,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    );
    
    EXPECT_TRUE(mat1 == mat2);
    EXPECT_TRUE(mat1 != mat3);
    EXPECT_FALSE(mat2 == mat3);
}

TEST(MatTests, TestMat4Mult) {
    Mat4 m1(
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    );

    Mat4 m2(
        -2, 1, 2, 3,
        3, 2, 1, -1,
        4, 3, 6, 5,
        1, 2, 7, 8
    );

    Mat4 res(
        20, 22, 50, 48,
        44, 54, 114, 108,
        40, 58, 110, 102,
        16, 26, 46, 42
    );

    EXPECT_EQ(m1 * m2, res);
}

TEST(MatTests, TestMat4Vec4Mult) {
    Mat4 m(
        1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1, 
        0, 0, 0, 1
    );

    Vec4 v(1, 2, 3, 1);

    EXPECT_EQ(m * v, Vec4(18, 24, 33, 1));
} 

TEST(MatTests, TestMatMultIdMat) {
    Mat4 m(
        1, 2, 3, 4,
        2, 4, 4, 2,
        8, 6, 4, 1, 
        10, 12, 14, 16
    );

    EXPECT_EQ(IDENTITY_MATRIX * m, m);
}

TEST(MatTests, TestVecMultIdMat) {
    Vec4 v(1, 2, 3, 4);
    EXPECT_EQ(IDENTITY_MATRIX * v, v);
}

TEST(MatTests, TestMatTranspose) {
    Mat4 m(
        0, 9, 3, 0,
        9, 8, 0, 8,
        1, 8, 5, 3,
        0, 0, 5, 8
    );

    Mat4 mT(
        0, 9, 1, 0,
        9, 8, 8, 0,
        3, 0, 5, 5,
        0, 8, 3, 8
    );

    EXPECT_EQ(transpose(m), mT);
    EXPECT_EQ(transpose(IDENTITY_MATRIX), IDENTITY_MATRIX);
}

TEST(MatTests, TestMat2Det) {
    Mat2 m(
        1, 5,
        -3, 2
    );

    EXPECT_FLOAT_EQ(det(m), 17);
}

TEST(MatTests, TestSubmatrixMat4) {
    Mat4 m(
        -6, 1, 1, 6,
        -8, 5, 8, 6,
        -1, 0, 8, 2,
        -7, 1, -1, 1
    );

    Mat3 res(
        -6, 1, 6,
        -8, 8, 6,
        -7, -1, 1    
    );

    EXPECT_EQ(submatrix(m, 2, 1), res);

    Mat3 res2(
        5, 8, 6,
        0, 8, 2,
        1, -1, 1
    );

    EXPECT_EQ(submatrix(m, 0, 0), res2);
}

TEST(MatTests, TestSubmatrixMat3) {
    Mat3 m(
        1, 5, 0,
        -3, 2, 7,
        0, 6, -3
    );

    Mat2 res(
        -3, 2,
        0, 6
    );

    EXPECT_EQ(submatrix(m, 0, 2), res);
}