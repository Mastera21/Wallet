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

class Deposit{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* window);
	void handleEvent(sf::Event e, sf::RenderWindow*& _window);
	std::string getData();

private:
	void storWalletInfo();
	std::string readFromFile();

	//int _amount = 0;

	Text _depositText;
	Text _text;
	TextBox _textBox;

	Button _depostButton;
	Button _backButton;

	Wallet _wallet;
};

