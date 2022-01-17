#pragma once
//C system headers

//C++ system headers
#include <string>
//Other libraries headers

//Own components headers

//Forward declarations

class UpdateBalanceText {
public:
	virtual ~UpdateBalanceText() = default;
	virtual std::string updateText(std::string& input) = 0;
};