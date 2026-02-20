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
    return 0;
}
