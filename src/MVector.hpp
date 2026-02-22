#ifndef M_VECTOR_HPP
#define M_VECTOR_HPP

struct MVector {
    double x;
    double y;

    MVector& operator+=(const MVector& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    friend MVector operator+(MVector lhs, const MVector& rhs) {
        lhs += rhs;
        return lhs;
    }
};

#endif
