#include "Deposit.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Deposit::init() {
    if (EXIT_SUCCESS != _depositText.init("fonts/Roboto-Black.ttf", "Deposit", 36, sf::Color::White, sf::Vector2f(250, 50))) {
        std::cerr << "_deposit.init() failed.\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
void Deposit::deinit() {

}
void Deposit::draw(sf::RenderWindow* window) {
    _depositText.draw(*window);

}
void Deposit::handleEvent(sf::Event e) {

}