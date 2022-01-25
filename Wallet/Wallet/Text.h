#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
//Own components headers

//Forward declarations

class Text {
public:
	int32_t init(std::string path, std::string& name, int size, sf::Color color, sf::Vector2f pos);
	void draw(sf::RenderWindow& _window);
private:
	sf::Text _text;
	sf::Font _font;
};

