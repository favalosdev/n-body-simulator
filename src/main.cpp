#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include "Utils.hpp"
#include "Constants.hpp"
#include "World.hpp"

int main()
{
	print_sfml_info();

	World world;
	Body sun;

	world.add_body(sun);
	world.step();

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
