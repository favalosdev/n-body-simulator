#include <iostream>
#include <SFML/Config.hpp>
#include "Utils.hpp"
#include <cmath>

void print_sfml_info()
{
    std::cout << "SFML Version: "
              << SFML_VERSION_MAJOR << "."
              << SFML_VERSION_MINOR << "."
              << SFML_VERSION_PATCH << std::endl;
}
