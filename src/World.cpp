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

std::vector<double> World::calc_forces(int N) {
    std::vector<Body>::iterator itr;
    int N = bodies.size();
    std::vector<double> forces { std::vector(N) };

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

        forces[i] = net_forces;
    }

    return forces;
}

void World::apply_forces(std::vector<double>& f) {
    int N = f.size();
}

/*
This might seem redundant but it's necessary in case
more operations beyond applying forces is necessary
*/
void World::step() {
    calc_forces();
}
