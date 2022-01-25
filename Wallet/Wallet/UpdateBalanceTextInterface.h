#pragma once
//C system headers

//C++ system headers
#include <string>
//Other libraries headers

//Own components headers

//Forward declarations

class UpdateBalanceTextInterface {
public:
	virtual ~UpdateBalanceTextInterface() = default;
	virtual std::string updateBalanceTextInterface() = 0;
};