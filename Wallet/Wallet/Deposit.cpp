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

    if (EXIT_SUCCESS != _textBox.init("fonts/Roboto-Black.ttf", 20,sf::Vector2f(250,100), sf::Color::White, true)) {
        std::cerr << "_textBox.init() failed.\n";
        return EXIT_FAILURE;
    }
    _textBox.setLimit(true, 10);

    return EXIT_SUCCESS;
}
void Deposit::deinit() {
    
}
void Deposit::draw(sf::RenderWindow* window) {
    _depositText.draw(*window);
    _textBox.draw(*window);
}
void Deposit::handleEvent(sf::Event e) {
    if (e.type == sf::Event::TextEntered) {
        _textBox.handleEvent(e);
    }
    if (e.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        _textBox.setSelected(true);
    }
    if (e.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        _textBox.setSelected(false);
    }
}