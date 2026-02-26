#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include "MVector.hpp"
#include "Constants.hpp"

typedef struct {
	// Physical-only properties
	MVector v0;
	MVector r;
	float mass;
	float density;

	// UI properties
	sf::Color colour = COLOURS[rand() % sizeof(COLOURS)];

	float calc_radius()
	{
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
};

#endif
