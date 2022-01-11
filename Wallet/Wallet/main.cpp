//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers
#include "Text.h"



const int W = 600;
const int H = 700;

int main() {
    sf::RenderWindow window(sf::VideoMode(W, H), "Wallet");


    Text walletText;
    walletText.init("fonts/Roboto-Black.ttf", "Wallet", 36, sf::Color::White, sf::Vector2f(250, 50));

    Text balanceText;
    balanceText.init("fonts/Roboto-Thin.ttf", "Total Balance: 0.00", 20, sf::Color::White, sf::Vector2f(217, 100));

    Text depositeText;
    depositeText.init("fonts/Roboto-Thin.ttf", "Deposit:", 25, sf::Color::White, sf::Vector2f(250, 190));

    Text widrawText;
    widrawText.init("fonts/Roboto-Thin.ttf", "Withdraw:", 25, sf::Color::White, sf::Vector2f(245, 420));

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        //text
        walletText.draw(window);
        balanceText.draw(window);
        depositeText.draw(window);
        widrawText.draw(window);


        window.display();
    }

	return 0;
}