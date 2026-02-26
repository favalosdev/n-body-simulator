#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include "Utils.hpp"
#include "Constants.hpp"
#include "World.hpp"

void setup(World& world)
{
	Body b1;
	b1.r.x = 0.0;
	b1.r.y = 0.0;
	b1.mass = 20000.0;
	b1.density = 0.001;
	world.add_body(b1);

	Body b2;
	b2.r.x = 200.0;
	b2.r.y = 0.0;
	b2.mass = 20000.0;
	b2.density = 0.001;
	world.add_body(b2);

	Body b3;
	b3.r.x = 0.0;
	b3.r.y = 200.0;
	b3.mass = 20000.0;
	b3.density = 0.001;
	world.add_body(b3);
}

/*
Stuff that's pending:
1. Modify the main window's coordinate system
2. Place bodies according to their actual coordinates
3. Simulate small steps to see if everything is working
*/

void draw_bodies(World& world, sf::RenderWindow& window)
{
	for (auto& b : world.bodies) {
		float radius = b.calc_radius();
		sf::CircleShape shape(radius);
		shape.setFillColor(b.colour);
		shape.setPosition({ b.r.x, b.r.y });
		window.draw(shape);
	}
}

void handle_key_press(sf::Window& window, World& world, const auto* keyPressed)
{
	switch (keyPressed->scancode) {
		case sf::Keyboard::Scancode::Escape:
			window.close();
			break;

		case sf::Keyboard::Scancode::E:
			world.step();
			break;

		default:
			break;
	}
}

int main()
{
	srand(time(NULL));
	print_sfml_info();

	World world;
	setup(world);

	sf::RenderWindow window(sf::VideoMode( { WINDOW_WIDTH, WINDOW_HEIGHT } ), "N-Body Simulation");

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			} else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				handle_key_press(window, world, keyPressed);
			}
		}

		window.clear(sf::Color::Black);
		draw_bodies(world, window);
		window.display();
	}
}
