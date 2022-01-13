#include "MainMenu.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t MainMenu::init() {
    if (EXIT_SUCCESS != _walletText.init("fonts/Roboto-Black.ttf", "Wallet", 36, sf::Color::White, sf::Vector2f(250, 50))) {
        std::cerr << "_walletText.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _balanceText.init("fonts/Roboto-Thin.ttf", "Total Balance: 0.00", 20, sf::Color::White, sf::Vector2f(217, 100))) {
        std::cerr << "_balanceText.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _depostButton.init("fonts/Roboto-Thin.ttf", "Deposit", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_depostButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _depostButton.setPos(sf::Vector2f(200, 230));

    if (EXIT_SUCCESS != _withdrawButton.init("fonts/Roboto-Thin.ttf", "Withdraw", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_withdrawButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _withdrawButton.setPos(sf::Vector2f(200, 360));

    return EXIT_SUCCESS;
}
void MainMenu::deinit() {

}
void MainMenu::draw(sf::RenderWindow* _window) {
    //text
    _walletText.draw(*_window);
    _balanceText.draw(*_window);
    //button
    _depostButton.draw(*_window);
    _withdrawButton.draw(*_window);
}
void MainMenu::handleEvent(const sf::Event& e, sf::RenderWindow*& _window,  bool& _isDepositButtonPressed, bool& _isWithdrawButtonPressed) {
    if (sf::Event::MouseMoved) {
        if (_depostButton.isMouseHover(*_window)) {
            _depostButton.setBackColor(sf::Color::Green);
        }else {
            _depostButton.setBackColor(sf::Color::White);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_depostButton.isMouseHover(*_window)) {
            //std::cout << "_depostButton was Presed\n";
            _isDepositButtonPressed = true;
        }
    }

    if (sf::Event::MouseMoved) {
        if (_withdrawButton.isMouseHover(*_window)) {
            _withdrawButton.setBackColor(sf::Color::Green);
        }else {
            _withdrawButton.setBackColor(sf::Color::White);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_withdrawButton.isMouseHover(*_window)) {
           // std::cout << "_withdrawButton was Presed\n";
            _isWithdrawButtonPressed = true;
        }
    }
}