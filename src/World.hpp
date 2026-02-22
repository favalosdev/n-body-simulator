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

public:
	World();
	void add_body(const Body& b);
	void step();
	std::vector<Body*>& get_bodies();
};

#endif
