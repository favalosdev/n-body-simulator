#include <iterator>
#include <vector>
#include <iostream>

#include "World.hpp"
#include "Constants.hpp"
#include "Utils.hpp"

void World::add_body(const Body& b) {
    bodies.push_back(b);
}

std::vector<MVector> World::calc_forces() {
    std::vector<Body>::iterator it;
    std::vector<MVector> forces { std::vector<MVector>(bodies.size()) };

    for (it = bodies.begin(); it != bodies.end(); ++it) {
        std::vector<Body>::iterator inner_it;
        MVector net_force;
        float m_i = it->mass;
        MVector r_i = it->r;

        for (inner_it = bodies.begin(); inner_it != bodies.end(); ++inner_it) {
            if (it != inner_it) {
                float m_j = inner_it->mass;
                MVector r_j = inner_it->r;
                MVector diff = r_j - r_i;
                MVector dir = diff.direction();
                float d2 = pow(diff.magnitude(), 2);
                net_force += dir * ((G * m_i * m_j) / d2);
            }
        }

        size_t i = it - bodies.begin();
        forces[i] = net_force;
    }

    return forces;
}

void World::apply_forces(std::vector<MVector>& f) {
    std::vector<Body>::iterator it;
    
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        size_t i = it - bodies.begin();
        MVector force = f[i];
        MVector a = force * (1.0 / it->mass);
        it->r += (it->v0 * TIME_DELTA) + (a * (pow(TIME_DELTA, 2) * 0.5));
    } 
}

void World::step() {
    std::vector<MVector> f = calc_forces();
    apply_forces(f);
}
