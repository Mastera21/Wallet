#include "Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

void Application::init() {

    const int W = 600;
    const int H = 700;

    _window = new sf::RenderWindow(sf::VideoMode(W, H), "Wallet");

    _walletText.init("fonts/Roboto-Black.ttf", "Wallet", 36, sf::Color::White, sf::Vector2f(250, 50));

    _balanceText.init("fonts/Roboto-Thin.ttf", "Total Balance: 0.00", 20, sf::Color::White, sf::Vector2f(217, 100));

    _depositeText.init("fonts/Roboto-Thin.ttf", "Deposit:", 25, sf::Color::White, sf::Vector2f(250, 190));

    _widrawText.init("fonts/Roboto-Thin.ttf", "Withdraw:", 25, sf::Color::White, sf::Vector2f(245, 420));

    _depostButton.init("fonts/Roboto-Thin.ttf", "Deposit", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black);
    _depostButton.setPos(sf::Vector2f(200, 230));

    _withdrawButton.init("fonts/Roboto-Thin.ttf", "Withdraw", sf::Vector2f(200, 50), 20, sf::Color::White, sf::Color::Black);
    _withdrawButton.setPos(sf::Vector2f(200, 460));
}
void Application::main() {
    init();

    while (_window->isOpen()) {
        bool wantToExit = update();
        if (wantToExit) {
            _window->close();
        }
        draw();
    }
    deinit();
}
void Application::run() {
    Application app;
    app.main();
}
bool Application::update() {
    sf::Event e;
    while (_window->pollEvent(e)) {
        if (checkForExit(e)) {
            return true;
            break;
        }

        handleEvent(e, _window);
    }
    return false;
}
void Application::handleEvent(sf::Event& e, sf::RenderWindow*& _window) {
    if (sf::Event::MouseMoved) {
        if (_depostButton.isMouseHover(*_window)) {
            _depostButton.setBackColor(sf::Color::Green);
        }
        else {
            _depostButton.setBackColor(sf::Color::White);
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_depostButton.isMouseHover(*_window)) {
            std::cout << "is Presed\n";
        }
        else {
            std::cout << "is not Presed\n";
        }
    }

    if (sf::Event::MouseMoved) {
        if (_withdrawButton.isMouseHover(*_window)) {
            _withdrawButton.setBackColor(sf::Color::Green);
        }
        else {
            _withdrawButton.setBackColor(sf::Color::White);
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_withdrawButton.isMouseHover(*_window)) {
            std::cout << "is Presed\n";
        }
        else {
            std::cout << "is not Presed\n";
        }
    }
}
void Application::draw() {
    _window->clear(sf::Color::Black);
    //text
    _walletText.draw(*_window);
    _balanceText.draw(*_window);
    _depositeText.draw(*_window);
    _widrawText.draw(*_window);
    //button
    _depostButton.draw(*_window);
    _withdrawButton.draw(*_window);

    _window->display();
}
void Application::deinit() {
	delete _window;
}
bool Application::checkForExit(sf::Event& e) {
    return (e.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}