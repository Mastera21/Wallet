#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include <cstdint>
//Own components headers
#include "Text.h"

//Forward declarations

class Withdraw{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* window);
	void handleEvent(sf::Event e);

private:
	Text _withdrawText;
};

