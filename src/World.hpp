#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "MVector.hpp"

typedef struct {
	MVector position;
	double mass;
} Body;

class World {
private:
	std::vector<Body> bodies;
	std::vector<double> calc_forces();
	void apply_forces(std::vector<double>& f);

public:
	World();
	void add_body(const Body& b);
	void step();
	const std::vector<Body>& get_bodies();
};

#endif
