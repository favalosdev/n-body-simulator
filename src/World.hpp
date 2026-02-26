#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <cmath>

#include "MVector.hpp"

typedef struct {
	MVector v0;
	MVector r;
	float mass;
	float density;

	float calc_radius() {
		return cbrt((3 * mass) / (4 * M_PI * density));
	}
} Body;

class World {
private:
	std::vector<MVector> calc_forces();
	void apply_forces(std::vector<MVector>& f);

public:
	std::vector<Body> bodies {};
	void add_body(const Body& b);
	void step();
	const std::vector<Body>& get_bodies();
};

#endif
