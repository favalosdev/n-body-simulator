#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>
#include "utils.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Body {
public:
	double x;
	double y;
	double mass;

	Body(double x, double y, double mass) {
		x = x;
		y = y;
		mass = mass;
	}
};

int main()
{
	print_sfml_info();

	sf::RenderWindow window(sf::VideoMode( { WINDOW_WIDTH, WINDOW_HEIGHT } ), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

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
