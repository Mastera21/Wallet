#include "Deposit.h"

//C system headers

//C++ system headers
#include <iostream>
#include <fstream>
//Other libraries headers

//Own components headers

int32_t Deposit::init() {
    if (EXIT_SUCCESS != _depositText.init("fonts/Roboto-Black.ttf", "Deposit", 36, sf::Color::White, sf::Vector2f(230, 50))) {
        std::cerr << "_deposit.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _text.init("fonts/Roboto-Thin.ttf", "Amount here:", 20, sf::Color::White, sf::Vector2f(200, 220))) {
        std::cerr << "_deposit.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _textBox.init("fonts/Roboto-Black.ttf", 20,sf::Vector2f(200,250), sf::Color::White, true)) {
        std::cerr << "_textBox.init() failed.\n";
        return EXIT_FAILURE;
    }
    _textBox.setLimit(true, 10);

    if (EXIT_SUCCESS != _depostButton.init("fonts/Roboto-Thin.ttf", "Deposit", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_depostButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _depostButton.setPos(sf::Vector2f(200, 500));

    if (EXIT_SUCCESS != _backButton.init("fonts/Roboto-Thin.ttf", "back", sf::Vector2f(70, 40), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_depostButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _backButton.setPos(sf::Vector2f(50, 510));

    return EXIT_SUCCESS;
}
void Deposit::deinit() {
    
}
std::string Deposit::getData() {
   return _textBox.getText();
}
void Deposit::draw(sf::RenderWindow* window) {
    _depositText.draw(*window);
    _textBox.draw(*window);
    _text.draw(*window);
    _depostButton.draw(*window);
    _backButton.draw(*window);
}
void Deposit::handleEvent(sf::Event e, sf::RenderWindow*& _window) {

    if (e.type == sf::Event::MouseMoved) {
        if (_depostButton.isMouseHover(*_window)) {
            _depostButton.setBackColor(sf::Color::Green);
        }else {
            _depostButton.setBackColor(sf::Color::White);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_depostButton.isMouseHover(*_window)) {
            //getting informatin from textbox
            storWalletInfo();
        }
    }

    if (e.type == sf::Event::MouseMoved) {
        if (_backButton.isMouseHover(*_window)) {
            _backButton.setBackColor(sf::Color::Green);
        }else {
            _backButton.setBackColor(sf::Color::White);
        }
    }
    if (e.type == sf::Event::TextEntered) {
        _textBox.handleEvent(e);
    }
}

void Deposit::storWalletInfo() {
    std::ofstream outFile;
    outFile.open("WalletAmount.txt");

    double sum = std::stod(getData());
    _wallet.deposit(sum);
    outFile << _wallet.getBalance();

    outFile.close();
}