#pragma once


//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers
#include "Text.h"
#include "Button.h"

//Forward declarations

class MainMenu{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* _window);
	void handleEvent(const sf::Event& e, sf::RenderWindow*& _window);

private:
	Text _walletText;
	Text _balanceText;

	Button _depostButton;
	Button _withdrawButton;
};

