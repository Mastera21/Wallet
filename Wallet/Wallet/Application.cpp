#include "Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

void Application::init() {

    const int W = 600;
    const int H = 600;

    _window = new sf::RenderWindow(sf::VideoMode(W, H), "Wallet");

    if (EXIT_SUCCESS != _ui.init()) {
        std::cerr << "_ui.init() failed.\n";
    }

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
void Application::handleEvent(sf::Event& e, sf::RenderWindow*& window) {
    _ui.handleEvent(e, window);
}
void Application::draw() {
    _window->clear(sf::Color::Black);
    
    _ui.draw(_window);

    _window->display();
}
void Application::deinit() {
    _ui.deinit();
    if (_window) {
        delete _window;
    }
}
bool Application::checkForExit(sf::Event& e) {
    return (e.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}