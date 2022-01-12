#pragma once

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MainMenu.h"
#include "Deposit.h"
#include "Withdraw.h"
//Forward declarations

class UI{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow* window);
	void handleEvent(const sf::Event& e, sf::RenderWindow*& window);

private:
	MainMenu _menu;
	Deposit _deposit;
	Withdraw _withdraw;

	bool _isDepositButtonPressed = false;
	bool _isWithdrawButtonPressed = false;
};

