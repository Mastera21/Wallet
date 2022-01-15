#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include <cstdint>
//Own components headers
#include "Text.h"
#include "TextBox.h"
#include "Button.h"
#include "Wallet.h"
//Forward declarations

class Withdraw{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* window);
	void handleEvent(sf::Event e, sf::RenderWindow*& _window);
	std::string getData();

private:
	Text _withdrawText;
	Text _text;
	TextBox _textBox;

	Button _withdrawButton;
	Button _backButton;

	Wallet _wallet;
};

