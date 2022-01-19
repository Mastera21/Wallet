#pragma once

//C system headers

//C++ system headers
#include <fstream>
//Other libraries headers

//Own components headers
#include "MainMenu.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "UpdateBalanceText.h"
//Forward declarations

class UI : public UpdateBalanceText{
public:
	int32_t init();
	void deinit();
	void draw(sf::RenderWindow*& window);
	void handleEvent(sf::Event& e, sf::RenderWindow*& window);

private:
	MainMenu _menu;
	Deposit _deposit;
	Withdraw _withdraw;
	
	std::string updateText(std::string& input) final;

	std::string readFromFile();
	std::string _balance;

	bool _isDepositButtonPressed = false;
	bool _isWithdrawButtonPressed = false;
	bool _isBackButtonPressed = false;
};

