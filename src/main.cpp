#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include "Utils.hpp"
#include "Constants.hpp"
#include "World.hpp"

void setup(World& world) {
	Body b1;
	b1.r.x = 0.0;
	b1.r.y = 0.0;
	b1.mass = 20000.0;
	b1.density = 0.001;

	Body b2;
	b2.r.x = 5.0;
	b2.r.y = 0.0;
	b2.mass = 15000.0;
	b2.density = 0.001;

	Body b3;
	b3.r.x = 10.0;
	b3.r.y = 0.0;
	b3.mass = 18000.0;
	b3.density = 0.001;

	world.add_body(b1);
	world.add_body(b2);
	world.add_body(b3);
}

void draw_bodies(World& world, sf::RenderWindow& window) {
	std::vector<Body> bodies = world.bodies;

	for (auto& element : bodies) {
		float radius = element.calc_radius();
		sf::CircleShape shape(radius);
		shape.setFillColor(sf::Color::Red);
		window.draw(shape);
	}
}

int main()
{
	print_sfml_info();

	World world;
	setup(world);

	sf::RenderWindow window(sf::VideoMode( { WINDOW_WIDTH, WINDOW_HEIGHT } ), "N-Body Simulation");

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear();
		draw_bodies(world, window);
		window.display();
	}
}
