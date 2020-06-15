#include <math.h>

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
    inline vec4& operator+=(const vec4&);
    inline vec4& operator-=(const vec4&);
    //inline vec4 operator+(const vec4&);
    //inline vec4 operator-(const vec4&);
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

inline vec4 operator-(const vec4 &other) {

}