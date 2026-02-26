#ifndef M_VECTOR_HPP
#define M_VECTOR_HPP

#include <cmath>

struct MVector {
    float x = 0.0;
    float y = 0.0;

    MVector& operator+=(const MVector& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    friend MVector operator+(MVector lhs, const MVector& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend MVector operator*(MVector lhs, const float& rhs) {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }

    MVector& operator-=(const MVector& rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    friend MVector operator-(MVector lhs, const MVector& rhs) {
        lhs -= rhs;
        return lhs;
    }

    MVector direction() {
        float m = this->magnitude();
        MVector v;
        v.x = this->x / m;
        v.y = this->y / m;
        return v;
    }

    float magnitude() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
};

#endif
