#pragma once
#include <vector>
#include "Power.h"

class straight:public Power
{
public:
	straight(std::vector <char> cards);
	virtual Result Compare(Power& other);
};

