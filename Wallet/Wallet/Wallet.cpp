#include "Wallet.h"
//C system headers

//C++ system headers
#include <iostream>
#include <fstream>
//Other libraries headers

//Own components headers

void Wallet::deposit(int num) {
	_balance += num;
}
void Wallet::withdraw(int num) {
	if (num > _balance) {
		std::cerr << "Not enough money in this wallet\n";
	}
	int result = std::abs(_balance - num);
	_balance = result;
}
int Wallet::getBalance() {
	return _balance;
}