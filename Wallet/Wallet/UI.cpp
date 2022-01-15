#include "UI.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t UI::init() {
    if (EXIT_SUCCESS != _menu.init()) {
        std::cerr << "_menu.init() failed.\n";
        return EXIT_FAILURE;
    }
    if (EXIT_SUCCESS != _deposit.init()) {
        std::cerr << "_deposit.init() failed.\n";
        return EXIT_FAILURE;
    }
    if (EXIT_SUCCESS != _withdraw.init()) {
        std::cerr << "_withdraw.init() failed.\n";
        return EXIT_FAILURE;
    }

    _isDepositButtonPressed = false;
    _isWithdrawButtonPressed = false;
    _isBackButtonPressed = false;

    return EXIT_SUCCESS;
}
void UI::deinit() {
    _withdraw.deinit();
    _deposit.deinit();
    _menu.deinit();
}
void UI::handleEvent(const sf::Event& e, sf::RenderWindow*& window) {
   if (!_isBackButtonPressed) {
       if (_isDepositButtonPressed) {
           _deposit.handleEvent(e, window, _isBackButtonPressed);
       }else if (_isWithdrawButtonPressed) {
           _withdraw.handleEvent(e, window, _isBackButtonPressed);
       }else {
          _menu.handleEvent(e, window, _isDepositButtonPressed, _isWithdrawButtonPressed);
       }
   }else {
       if (!_isDepositButtonPressed) {
           _deposit.handleEvent(e, window, _isBackButtonPressed);
       }else if(!_isWithdrawButtonPressed){
           _withdraw.handleEvent(e, window, _isBackButtonPressed);
       }else {
           _menu.handleEvent(e, window, _isDepositButtonPressed, _isWithdrawButtonPressed);
       }
   }
}
void UI::draw(sf::RenderWindow* window) {
   if (!_isBackButtonPressed) {
       if (_isDepositButtonPressed) {
           _deposit.draw(window);
       }else if (_isWithdrawButtonPressed) {
           _withdraw.draw(window);
       }else {
           _menu.draw(window);
       }
   }else {
       _menu.draw(window);
       _isDepositButtonPressed = false;
       _isWithdrawButtonPressed = false;
       _isBackButtonPressed = false;
   }
}