#pragma once

//C system headers

//C++ system headers
#include <fstream>
#include <memory>
//Other libraries headers

//Own components headers
#include "UI.h"
#include "UpdateBalanceTextInterface.h"
//Forward declarations

class Application : public UpdateBalanceTextInterface {
public:
	static void run();
private:
	void init();
	void main();
	bool update();
	void draw();
	void handleEvent(sf::Event& e, std::shared_ptr<sf::RenderWindow>& window);
	bool checkForExit(sf::Event& e);
	void deinit();

	std::string readFromFile();
	std::string updateBalanceTextInterface() final;

	std::shared_ptr<sf::RenderWindow> _window = nullptr;
	UI _ui;
};

