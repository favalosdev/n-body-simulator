#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include "Utils.hpp"
#include "Constants.hpp"
#include "World.hpp"

void setup(World& world) {
	Body b1;
	b1.r.x = 0.0;
	b1.r.y = 0.0;
	b1.mass = 1.0;
	b1.density = 1.0;

	Body b2;
	b2.r.x = 5.0;
	b2.r.y = 0.0;
	b2.mass = 1.0;
	b2.density = 1.0;

	world.add_body(b1);
	world.add_body(b2);
}

int main()
{
	print_sfml_info();

	World world;
	setup(world);

	sf::RenderWindow window(sf::VideoMode( { WINDOW_WIDTH, WINDOW_HEIGHT } ), "N-Body Simulation");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}
