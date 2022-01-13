#include "Wallet.h"
//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

void Wallet::deposit(double num) {
	_balance += num;
}
void Wallet::withdraw(double num) {
	if (num > _balance) {
		std::cerr << "Not enough money in this wallet\n";
	}
	double result = std::abs(_balance - num);
	_balance = result;
}
std::string Wallet::getBalance() {
	return  std::to_string(_balance);
}