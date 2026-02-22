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

    friend X operator+(X lhs, const X& rhs) {
        lhs += rhs;
        return lhs;
    }
};

double euclidean_dist(const MVector& p1, const MVector& p2) {
    return 1.0;
}

#endif
