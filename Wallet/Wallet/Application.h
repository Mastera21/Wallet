#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include <SFML/Graphics.hpp>
//Own components headers
#include "Text.h"
#include "Button.h"

//Forward declarations

class Application{
public:
	static void run();
private:
	void init();
	void main();
	bool update();
	void draw();
	void handleEvent(sf::Event& e, sf::RenderWindow*& _window);
	bool checkForExit(sf::Event& e);
	void deinit();

	sf::RenderWindow* _window = nullptr;

	Text _walletText;
	Text _balanceText;
	Text _depositeText;
	Text _widrawText;

	Button _depostButton;
	Button _withdrawButton;
};

