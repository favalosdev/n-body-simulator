#ifndef M_VECTOR_HPP
#define M_VECTOR_HPP

typedef struct {
    double x;
    double y;
} MVector;

double euclidean_dist(MVector p1, MVector p2);

#endif
