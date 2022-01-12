#include "UI.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t UI::init() {
    if (EXIT_SUCCESS != _menu.init()) {
        std::cerr << "_menu.init() failed.\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
void UI::deinit() {
    _menu.deinit();
}
void UI::draw(sf::RenderWindow* _window) {
    _menu.draw(_window);
}
void UI::handleEvent(const sf::Event& e, sf::RenderWindow*& window) {
    _menu.handleEvent(e, window);
}