#include "Withdraw.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Withdraw::init() {
    if (EXIT_SUCCESS != _withdrawText.init("fonts/Roboto-Black.ttf", "Withdraw", 36, sf::Color::White, sf::Vector2f(250, 50))) {
        std::cerr << "_deposit.init() failed.\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
void Withdraw::deinit() {

}
void Withdraw::draw(sf::RenderWindow* window) {
    _withdrawText.draw(*window);

}
void Withdraw::handleEvent(sf::Event e) {

}