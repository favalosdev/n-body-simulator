#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <cmath>

#include "MVector.hpp"

typedef struct {
	MVector velocity;
	MVector position;
	double mass;
	double density;

	double calc_radius() {
		return cbrt((3 * mass)/(4 * M_PI * density));
	}
} Body;

class World {
private:
	std::vector<Body> bodies;
	std::vector<MVector> calc_forces();
	void apply_forces(std::vector<MVector>& f);

public:
	World();
	void add_body(const Body& b);
	void step();
	const std::vector<Body>& get_bodies();
};

#endif
