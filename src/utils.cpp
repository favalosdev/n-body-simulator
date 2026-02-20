#include <iostream>
#include <SFML/Config.hpp>
#include "utils.hpp"

void print_sfml_info()
{
    std::cout << "SFML Version: "
              << SFML_VERSION_MAJOR << "."
              << SFML_VERSION_MINOR << "."
              << SFML_VERSION_PATCH << std::endl;
}
