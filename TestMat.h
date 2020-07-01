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

TEST(MatTests, TestMinorMat3) {
    Mat3 m(
        3, 5, 0,
        2, -1, -7,
        6, -1, 5
    );

    EXPECT_FLOAT_EQ(minor(m, 1, 0), 25);
}

TEST(MatTests, TestCofactorMat3) {
    Mat3 m(
        3, 5, 0,
        2, -1, -7,
        6, -1, 5
    );
    
    EXPECT_FLOAT_EQ(cofactor(m, 0, 0), -12);
    EXPECT_FLOAT_EQ(cofactor(m, 1, 0), -25);
}

TEST(MatTests, TestDetMat3) {
    Mat3 m(
        1, 2, 6,
        -5, 8, -4,
        2, 6, 4
    );

    EXPECT_FLOAT_EQ(det(m), -196);
}

TEST(MatTests, TestDetMat4) {
    Mat4 m(
        -2, -8, 3, 5,
        -3, 1, 7, 3,
        1, 2, -9, 6,
        -6, 7, 7, -9
    );

    EXPECT_FLOAT_EQ(det(m), -4071);
}

TEST(MatTests, TestInvertibleMat4) {
    Mat4 m(
        6, 4, 4, 4,
        5, 5, 7, 6,
        4, -9, 3, -7,
        9, 1, 7, -6
    );

    EXPECT_FLOAT_EQ(det(m), -2120);
    EXPECT_TRUE(isInvertible(m));

    Mat4 m2(
        -4, 2, -2, -3,
        9, 6, 2, 6,
        0, -5, 1, -5,
        0, 0, 0 ,0 
    );

    EXPECT_FLOAT_EQ(det(m2), 0);
    EXPECT_FLOAT_EQ(isInvertible(m2), 0);
}

TEST(MatTests, TestInverseMat4) {
    Mat4 m(
        9, 3, 0, 9,
        -5, -2, -6, -3,
        -4, 9, 6, 4, 
        -7, 6, 6, 2
    );

    Mat4 res(
        -0.04074f, -0.07778f, 0.14444f, -0.22222f,
        -0.07778f, 0.03333f, 0.36667f, -0.33333f,
        -0.02901f, -0.14630f, -0.10926f, 0.12963f,
        0.17778f, 0.06667f, -0.26667f, 0.33333f
    );

    Mat4 m2(
        3, -9, 7, 3,
        3, -8, 2, -9,
        -4, 4, 4, 1,
        -6, 5, -1, 1
    );

    Mat4 m3(
        8, 2, 2, 2,
        3, -1, 7, 0,
        7, 0, 5, 4,
        6, -2, 0, 5
    );

    //printMat(inverse(m));
    EXPECT_EQ(inverse(m), res);

    Mat4 prod = m2 * m3;
    EXPECT_EQ(prod * inverse(m3), m2);
}