#pragma once

//C system headers

//C++ system headers
#include <iostream>
#include <sstream>
//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers

//Forward declarations

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox{
public:
	int32_t init(std::string path, int size, sf::Vector2f pos, sf::Color color, bool selected);
	void draw(sf::RenderWindow& window);
	void handleEvent(sf::Event e);

	std::string getText();
	void setLimit(bool trueORfalse);
	void setLimit(bool trueORfalse, int limit);
	void setSelected(bool selected);

private:
	void inputLogic(int charType);
	void deleteLastChar();

	sf::Font _font;
	sf::Text _textBox;
	std::ostringstream _text;
	bool _isSelected = false;
	bool _hasLimit = false;
	int _limit;
};

