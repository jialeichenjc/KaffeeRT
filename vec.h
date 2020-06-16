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

class vec4 {
public: 
    float x, y, z, w;
    vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    vec4(float x, float y, float z, float w = 0.0f) : x(x), y(y), z(z), w(w) {}
    inline bool operator==(const vec4 &) const;
    inline vec4 operator-() const; // negation
    inline vec4& operator+=(const vec4&); // not implemented yet...not sure if I'll need them
    inline vec4& operator-=(const vec4&);
};

class point : public vec4 {

};


inline bool vec4::operator==(const vec4 &other) const {
    return (abs(x - other.x) < EPSILON) && (abs(y - other.y) < EPSILON) && (abs(z - other.z) < EPSILON);
}

inline vec4 operator+(const vec4 &v1, const vec4 &v2) {
    return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline vec4 operator-(const vec4 &v1, const vec4 &v2) {
    return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

// negate
inline vec4 vec4::operator-() const{
    return vec4(-x, -y, -z);
}

// scalar multi and div
inline vec4 operator*(const vec4 &v1, float t) {
    return vec4(v1.x * t, v1.y * t, v1.z * t);
}

inline vec4 operator*(float t, const vec4 &v1) {
    return vec4(v1.x * t, v1.y * t, v1.z * t);
}

inline vec4 operator/(const vec4 &v1, float t) {
    assert(t != 0);
    return vec4(v1.x / t, v1.y / t, v1.z / t);
}

// length
inline float mag(const vec4 &v1) {
    return sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
}

// normalize
inline vec4 norm(const vec4 &v1) {
    float u = 1 / mag(v1);
    return vec4(v1.x * u, v1.y * u, v1.z * u);
}

// TODO: I'm not sure if I'm including w here for any reason
// w could potentially be 1 if I end up using homogeneous coord
inline float dot(const vec4 &v1, const vec4 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline vec4 cross(const vec4 &v1, const vec4 &v2) {
    return vec4(v1.y * v2.z - v1.z * v2.y, 
                v1.z * v2.x - v1.x * v2.z,
                v1.x * v2.y - v1.y * v2.x);
}