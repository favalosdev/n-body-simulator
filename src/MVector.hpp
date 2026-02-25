#ifndef M_VECTOR_HPP
#define M_VECTOR_HPP

#include <cmath>

struct MVector {
    double x = 0.0;
    double y = 0.0;

    MVector& operator+=(const MVector& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    friend MVector operator+(MVector lhs, const MVector& rhs) {
        lhs += rhs;
        return lhs;
    }

    friend MVector operator*(MVector lhs, const double& rhs) {
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
        double m = this->magnitude();
        MVector v;
        v.x = this->x / m;
        v.y = this->y / m;
        return v;
    }

    double magnitude() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
};

#endif
