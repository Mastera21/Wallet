#pragma once

//C system headers

//C++ system headers
#include <string>
//Other libraries headers

//Own components headers

//Forward declarations

class Wallet{
public:
	void deposit(double num);
	void withdraw(double num);
	std::string getBalance();
private:
	double _balance;
};

