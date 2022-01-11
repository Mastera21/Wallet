//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers

const int W = 600;
const int H = 700;

int main() {
    sf::RenderWindow window(sf::VideoMode(W, H), "Wallet");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

	return 0;
}