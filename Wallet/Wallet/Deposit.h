#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include <cstdint>
//Own components headers
#include "Text.h"
#include "TextBox.h"
//Forward declarations

class Deposit{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* window);
	void handleEvent(sf::Event e);

private:
	Text _depositText;
	TextBox _textBox;
};

