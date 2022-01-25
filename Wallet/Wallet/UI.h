#pragma once

//C system headers

//C++ system headers
//Other libraries headers

//Own components headers
#include "MainMenu.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "UpdateBalanceText.h"
#include "UpdateBalanceTextInterface.h"
//Forward declarations

class UI : public UpdateBalanceText {
public:
	int32_t init(UpdateBalanceTextInterface* test);
	void deinit();
	void draw(sf::RenderWindow*& window);
	void handleEvent(sf::Event& e, sf::RenderWindow*& window);
private:
	std::string updateText() final;

	MainMenu _menu;
	Deposit _deposit;
	Withdraw _withdraw;

	UpdateBalanceTextInterface* _updateBalanceText = nullptr;

	std::string _balance;
	bool _isDepositButtonPressed = false;
	bool _isWithdrawButtonPressed = false;
	bool _isBackButtonPressed = false;
};

