#include <iterator>
#include <vector>
#include <iostream>

#include "World.hpp"
#include "Constants.hpp"
#include "Utils.hpp"

World::World() {
    std::vector<Body> init {};
    bodies = init;
}

void World::add_body(const Body& b) {
    bodies.push_back(b);
}

std::vector<MVector> World::calc_forces() {
    std::vector<Body>::iterator itr;
    std::vector<MVector> forces { std::vector<MVector>(bodies.size()) };

    for (itr = bodies.begin(); itr != bodies.end(); itr++) {
        std::vector<Body>::iterator inner_itr;
        MVector net_force;
        double m_i = itr->mass;
        MVector r_i = itr->r;

        for (inner_itr = bodies.begin(); inner_itr != bodies.end(); inner_itr++) {
            if (itr != inner_itr) {
                double m_j = inner_itr->mass;
                MVector r_j = inner_itr->r;
                MVector diff = r_j - r_i;
                MVector dir = diff.direction();
                double d2 = pow(diff.magnitude(), 2);
                net_force += dir * ((G * m_i * m_j) / d2);
            }
        }

        size_t i = itr - bodies.begin();
        forces[i] = net_force;
    }

    return forces;
}

void World::apply_forces(std::vector<MVector>& f) {
    std::vector<Body>::iterator itr;
    
    for (itr = bodies.begin(); itr != bodies.end(); itr++) {
        size_t i = itr - bodies.begin();
        MVector force = f[i];
        MVector a = force * (1.0 / itr->mass);
        itr->r += (itr->v0 * TIME_DELTA) + (a * (pow(TIME_DELTA, 2) * 0.5));
    } 
}

void World::step() {
    std::vector<MVector> f = calc_forces();
    apply_forces(f);
}
