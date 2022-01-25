#pragma once
//C system headers

//C++ system headers

//Other libraries headers
// 
//Own components headers
#include "Text.h"
#include "Button.h"
#include "TextBox.h"
#include "UpdateBalanceText.h"
//Forward declarations

class MainMenu{
public:
	int32_t init(UpdateBalanceText* updateBalanceText);
	void deinit();
	void draw(sf::RenderWindow* _window);
	void handleEvent(const sf::Event& e, sf::RenderWindow*& _window, bool& _isDepositButtonPressed, bool& _isWithdrawButtonPressed);
private:
	UpdateBalanceText* _updateBalanceText = nullptr;

	Text _walletText;
	Text _balanceText;

	Button _depostButton;
	Button _withdrawButton;
};

