#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void print_sfml_version()
{
    std::cout << "SFML Version: "
              << SFML_VERSION_MAJOR << "."
              << SFML_VERSION_MINOR << "."
              << SFML_VERSION_PATCH << std::endl;
}

int main()
{
    sf::Window window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "My window");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}
