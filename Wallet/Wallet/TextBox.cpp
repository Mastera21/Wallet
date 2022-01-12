#include "TextBox.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t TextBox::init(std::string path, int size, sf::Vector2f pos, sf::Color color, bool selected) {
	if (!_font.loadFromFile(path)) {
		std::cerr << "Cannot open font for file -> TextBox::init()\n";
		return EXIT_FAILURE;
	}
	_textBox.setFont(_font);
	_textBox.setCharacterSize(size);
	_textBox.setFillColor(color);
	_textBox.setPosition(pos);
	_isSelected = selected;

	if (selected) {
		_textBox.setString("_");
	}else {
		_textBox.setString("");
	}
	_text.clear();

	return EXIT_SUCCESS;
}
void TextBox::draw(sf::RenderWindow& window) {
	window.draw(_textBox);
}
void TextBox::handleEvent(sf::Event e) {
	if (_isSelected) {
		int charType = e.text.unicode;
		if (charType < 128) {
			if (_hasLimit) {
				if (_text.str().length() <= _limit) {
					inputLogic(charType);
				}else if (_text.str().length() > _limit && charType == DELETE_KEY) {
					deleteLastChar();
				}
			}else {
				inputLogic(charType);
			}
		}
	}
}

std::string TextBox::getText() {
	return _text.str();
}
void TextBox::setLimit(bool trueORfalse) {
	_hasLimit = trueORfalse;
}
void TextBox::setLimit(bool trueORfalse, int limit) {
	_hasLimit = trueORfalse;
	_limit = limit;
}
void TextBox::setSelected(bool selected) {
	_isSelected = selected;
	if (!_isSelected) {
		std::string t = _text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++) {
			newT += t[i];
		}
		_textBox.setString(newT);
	}
}
void TextBox::inputLogic(int charType) {
	if (charType != DELETE_KEY && charType != ENTER_KEY && charType != ESCAPE_KEY) {
		_text << static_cast<char>(charType);
	}else if (charType == DELETE_KEY) {
		if (_text.str().length() > 0) {
			deleteLastChar();
		}
	}
	_textBox.setString(_text.str() + "_");
}
void TextBox::deleteLastChar() {
	std::string t = _text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++) {
		newT += t[i];
	}
	_text.str("");
	_text << newT;

	_textBox.setString(_text.str());
}