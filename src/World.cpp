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
        MVector p_i = itr->position;
        int i = itr - bodies.begin();

        for (inner_itr = bodies.begin(); inner_itr != bodies.end(); inner_itr++) {
            if (itr != inner_itr) {
                double m_j = inner_itr->mass;
                MVector p_j = inner_itr->position;
                MVector dir = (p_j - p_i).normalized();
                double d2 = pow(dir.magnitude(), 2);
                net_force += dir * ((G * m_i * m_j) / d2);
            }
        }

        forces[i] = net_force;
    }

    return forces;
}

void World::apply_forces(std::vector<MVector>& f) {
    int N = f.size();

}

void World::step() {
    std::vector<MVector> f = calc_forces();
    apply_forces(f);
}
