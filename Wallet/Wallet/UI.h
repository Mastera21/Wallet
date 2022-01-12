#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers
#include "MainMenu.h"

//Forward declarations

class UI{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* _window);
	void handleEvent(const sf::Event& e, sf::RenderWindow*& window);

private:
	MainMenu _menu;
};

