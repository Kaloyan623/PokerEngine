#pragma once
#include <vector>
#include "Power.h"

class four:public Power
{
public:
	four(std::vector <char> cards);
	virtual Result Compare(Power& other);
};

