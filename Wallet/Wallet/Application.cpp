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

    if (EXIT_SUCCESS != _ui.init(this)) {
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
        updateBalanceTextInterface();

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
    delete _window;
}
bool Application::checkForExit(sf::Event& e) {
    return (e.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}
std::string Application::readFromFile() {
    std::string xbalance = "Total Balance: ";

    std::ifstream file("WalletAmount.txt", std::ios::in);

    if (file.fail()) {
        std::cerr << "Cannot open WalletAmount.txt file\n";
        exit(1);
    }
    int amount = 0;
    file >> amount;
    xbalance.append(std::to_string(amount));
    file.close();
    return xbalance;
}
std::string Application::updateBalanceTextInterface() {
    std::string read = readFromFile();
    return read;
}