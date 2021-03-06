#include "Text.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Text::init(std::string path, std::string& name, int size, sf::Color color, sf::Vector2f pos) {
    if (!_font.loadFromFile(path)) {
        std::cerr << "Cannot open font for file -> Text::init()\n";
        return EXIT_FAILURE;
    }

    _text.setFont(_font);
    _text.setString(name);
    _text.setCharacterSize(size);
    _text.setFillColor(color);
    _text.setPosition(pos);

    return EXIT_SUCCESS;
}
void Text::draw(sf::RenderWindow& _window) {
    _window.draw(_text);
}