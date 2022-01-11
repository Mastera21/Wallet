#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers

//Forward declarations


class Button {
public:
	int32_t init(std::string path, std::string text, sf::Vector2f size, int textSize, sf::Color bgColor, sf::Color textColor);

	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPos(sf::Vector2f pos);
	void draw(sf::RenderWindow& _window);

	bool isMouseHover(sf::RenderWindow& _window);

private:
	sf::RectangleShape _button;
	sf::Text _text;
	sf::Font _font;
};

