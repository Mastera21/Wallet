#pragma once

//C system headers

//C++ system headers
#include <string>
//Other libraries headers

//Own components headers

//Forward declarations

class Wallet{
public:
	void deposit(int num);
	void withdraw(int num);
private:
	std::string readFromFile();
	void storWalletInfo();

	int _balance = 0;
};

