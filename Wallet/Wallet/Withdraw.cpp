#include "Withdraw.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Withdraw::init() {
    std::string textWithdraw = "Withdraw";
    if (EXIT_SUCCESS != _withdrawText.init("fonts/Roboto-Black.ttf", textWithdraw, 36, sf::Color::White, sf::Vector2f(225, 50))) {
        std::cerr << "_withdrawText.init() failed.\n";
        return EXIT_FAILURE;
    }
    std::string textAmount = "Amount here:";
    if (EXIT_SUCCESS != _text.init("fonts/Roboto-Thin.ttf", textAmount, 20, sf::Color::White, sf::Vector2f(200, 220))) {
        std::cerr << "_text.init() failed.\n";
        return EXIT_FAILURE;
    }
    std::string textNoMoney = "Not enough money in this wallet";
    if (EXIT_SUCCESS != _textError.init("fonts/Roboto-Thin.ttf", textNoMoney, 20, sf::Color::Red, sf::Vector2f(200, 280))) {
        std::cerr << "_textError.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _textBox.init("fonts/Roboto-Black.ttf", 20, sf::Vector2f(200, 250), sf::Color::White, true)) {
        std::cerr << "_textBox.init() failed.\n";
        return EXIT_FAILURE;
    }
    _textBox.setLimit(true, 10);

    if (EXIT_SUCCESS != _withdrawButton.init("fonts/Roboto-Thin.ttf", "Withdraw", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_withdrawButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _withdrawButton.setPos(sf::Vector2f(200, 500));

    if (EXIT_SUCCESS != _backButton.init("fonts/Roboto-Thin.ttf", "back", sf::Vector2f(70, 40), 20, sf::Color::White, sf::Color::Black)) {
        std::cerr << "_backButton.init() failed.\n";
        return EXIT_FAILURE;
    }
    _backButton.setPos(sf::Vector2f(50, 510));
    return EXIT_SUCCESS;
}
void Withdraw::deinit() {

}
void Withdraw::draw(std::shared_ptr<sf::RenderWindow>& window) {
    _withdrawText.draw(*window);
    _textBox.draw(*window);
    _text.draw(*window);
    _withdrawButton.draw(*window);
    _backButton.draw(*window);
    if (_isBigger) {
        _textError.draw(*window);
    }
}
void Withdraw::handleEvent(sf::Event& e, std::shared_ptr<sf::RenderWindow>& _window, bool& _isBackButtonPressed) {
    if (e.type == sf::Event::MouseMoved) {
        if (_withdrawButton.isMouseHover(*_window)) {
            _withdrawButton.setBackColor(sf::Color::Green);
        }else {
            _withdrawButton.setBackColor(sf::Color::White);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_withdrawButton.isMouseHover(*_window)) {
            //getting informatin from textbox
            int sum = std::stoi(getData());
            std::cout << "user withdraw: " << sum << "\n";

            if (isSumBiggerThenBalance(sum)) {
                _isBigger = true;
            }else {
                _isBigger = false;
                _wallet.withdraw(sum);
            }
        }
    }

    if (e.type == sf::Event::MouseMoved) {
        if (_backButton.isMouseHover(*_window)) {
            _backButton.setBackColor(sf::Color::Green);
        }else {
            _backButton.setBackColor(sf::Color::White);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_backButton.isMouseHover(*_window)) {
            _isBackButtonPressed = true;
        }
    }

    if (e.type == sf::Event::TextEntered) {
        _textBox.handleEvent(e);
    }
}
std::string Withdraw::getData() {
    return _textBox.getText();
}
bool Withdraw::isSumBiggerThenBalance(int sum) {
    int balance = 0;
    std::string amount = _wallet.readFromFile();
    balance = std::stoi(amount);

    if (sum > balance) {
        return true;
    }
    return false;
}