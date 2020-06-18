#pragma once

#include <math.h>
#include <assert.h>

#define EPSILON 0.00001

class tuple {
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = -1.0f; // 1 if tuple is a point, 0 if tuple is a vector;


private:

};

class Vec4 {
public: 
    float x, y, z, w;
    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vec4(float x, float y, float z, float w = 0.0f) : x(x), y(y), z(z), w(w) {}
    inline bool operator==(const Vec4 &) const;
    inline Vec4 operator-() const; // negation
    inline Vec4& operator+=(const Vec4&); // not implemented yet...not sure if I'll need them
    inline Vec4& operator-=(const Vec4&);
    ~Vec4() = default;
};

class point : public Vec4 {

};

class color : public Vec4 {

};

inline bool Vec4::operator==(const Vec4 &other) const {
    return (abs(x - other.x) < EPSILON) && (abs(y - other.y) < EPSILON) && (abs(z - other.z) < EPSILON);
}

inline Vec4 operator+(const Vec4 &v1, const Vec4 &v2) {
    return Vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline Vec4 operator-(const Vec4 &v1, const Vec4 &v2) {
    return Vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// negate
inline Vec4 Vec4::operator-() const{
    return Vec4(-x, -y, -z);
}

// scalar multi and div
inline Vec4 operator*(const Vec4 &v1, float t) {
    return Vec4(v1.x * t, v1.y * t, v1.z * t);
}

inline Vec4 operator*(float t, const Vec4 &v1) {
    return Vec4(v1.x * t, v1.y * t, v1.z * t);
}

inline Vec4 operator/(const Vec4 &v1, float t) {
    assert(t != 0);
    return Vec4(v1.x / t, v1.y / t, v1.z / t);
}

// length
inline float mag(const Vec4 &v1) {
    return sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
}

// normalize
inline Vec4 norm(const Vec4 &v1) {
    float u = 1 / mag(v1);
    return Vec4(v1.x * u, v1.y * u, v1.z * u);
}

// TODO: I'm not sure if I'm including w here for any reason
// w could potentially be 1 if I end up using homogeneous coord
inline float dot(const Vec4 &v1, const Vec4 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline Vec4 cross(const Vec4 &v1, const Vec4 &v2) {
    return Vec4(v1.y * v2.z - v1.z * v2.y, 
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}

// For color blending
inline Vec4 hadamardProd(const Vec4 &v1, const Vec4 &v2) {
    return Vec4(v1.x * v2.x,
                v1.y * v2.y,
                v1.z * v2.z);
}