#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <iostream>

void print_sfml_version()
{
    std::cout << "SFML Version: "
              << SFML_VERSION_MAJOR << "."
              << SFML_VERSION_MINOR << "."
              << SFML_VERSION_PATCH << std::endl;
}

int main()
{
    sf::Window window(sf::VideoMode({800, 600}), "My window");

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent()) {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }
}
