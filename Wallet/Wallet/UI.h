#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers
#include "Text.h"
#include "Button.h"

//Forward declarations

class UI{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* _window);
	void handleEvent(sf::Event& e, sf::RenderWindow*& _window);

private:
	Text _walletText;
	Text _balanceText;
	Text _depositeText;
	Text _widrawText;

	Button _depostButton;
	Button _withdrawButton;
};

