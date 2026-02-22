#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "MVector.hpp"

typedef struct {
	MVector position;
	MVector acceleration;
	double mass;
} Body;

class World {
private:
	std::vector<Body> bodies;

	void apply_forces();
	void step();

public:
	World();

	void add_body(Body b);
	void get_bodies();
};

#endif
