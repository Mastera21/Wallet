#include "Wallet.h"
//C system headers

//C++ system headers
#include <iostream>
#include <fstream>
//Other libraries headers

//Own components headers

std::string Wallet::readFromFile() {
    std::string balance = "";

    std::ifstream file("WalletAmount.txt", std::ios::in);

    if (file.fail()) {
        std::cerr << "Cannot open this file\n";
        exit(1);
    }
    int amount = 0;
    file >> amount;
    balance += std::to_string(amount);
    file.close();
    return balance;
}
void Wallet::storWalletInfo() {
    std::fstream outFile("WalletAmount.txt", std::ios::out);

    if (!outFile) {
        std::cerr << "File not created!\n";
    }else {
        outFile << _balance;
        outFile.close();
    }
}
void Wallet::deposit(int num) {
    std::string inputFromFile = readFromFile();
    _balance = std::stoi(inputFromFile);
	_balance = _balance + num;
    storWalletInfo();
}
void Wallet::withdraw(int num) {
    std::string inputFromFile = readFromFile();
    _balance = std::stoi(inputFromFile);
	if (num > _balance) {
		std::cerr << "Not enough money in this wallet\n";
	}
	int result = std::abs(_balance - num);
	_balance = result;
    storWalletInfo();
}