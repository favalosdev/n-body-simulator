#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <SFML/Graphics.hpp>

// UI constants
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// World constants
const float G = 6.67E-11;
const float TIME_DELTA = 0.01;

const sf::Color COLOURS[5] = {
    sf::Color::White,
    sf::Color::Red,
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Yellow
};

const sf::Color BACKGROUND_COLOUR = sf::Color::Black;

#endif
